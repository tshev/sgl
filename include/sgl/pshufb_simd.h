#pragma once
#include <cstdint>

#define force_inline alway_inline

namespace sgl {
// gcc
inline
int popcount(unsigned int n) {
  // count of nonzeros bits
  return __builtin_popcount(n);
}

// gcc
inline
int count_trailing_zeros(unsigned int n) {
  if (n == 0) {
    return 32;
  } else {
    // Returns the number of trailing 0-bits in x, starting at the least significant bit position.
    // If x is 0, the result is undefined.
    return __builtin_ctz(n);
  }
}

// gcc
inline
int count_leading_zeros(unsigned int n) {
  static_assert(sizeof(unsigned int) == 4);
  // Returns the number of leading 0-bits in x, starting at the most significant bit position.
  // If x is 0, the result is undefined. 
  if (n == 0) {
    return 32;
  } else {
    return __builtin_clz(n);
  }
}

// gcc
inline
int count_trailing_ones(unsigned int n) {
  return count_trailing_zeros(~n);
}

// gcc
inline
int count_leading_ones(unsigned int n) {
  return count_leading_zeros(~n);
}

// gcc
typedef char aligned16byte_t __attribute__ ((vector_size (16)));
//typedef v16qi aligned16byte_t;

inline
aligned16byte_t load_unaligned128(const char* p) {
  return __builtin_ia32_loaddqu(p);
}


inline
aligned16byte_t load_unaligned128(const uint8_t* p) {
  return __builtin_ia32_loaddqu((const char*)(p));
}

inline
void store_unaligned128(aligned16byte_t src, uint8_t* dst) {
  __builtin_ia32_storedqu((char*)(dst), src);
}


//  -mssse4.1
inline
void shuffle_and_store128(aligned16byte_t src, const aligned16byte_t& shuffle, uint8_t* dst) {
  store_unaligned128(__builtin_ia32_pshufb128(src, shuffle), dst);
}


template<size_t n>
struct shuffle {
  static const constexpr size_t shuffle_size = n;

  const aligned16byte_t* ptr;

  shuffle(const aligned16byte_t* ptr) : ptr(ptr) {}
};

/************************************ Bit Manimulation Functions ***************************************/
inline
uint8_t leading_ones_in_byte(uint8_t byte) {
  return uint8_t(count_leading_ones(0xffffff00 | uint32_t(byte)) - 24);
}

inline
uint8_t number_of_zeros_in_byte(uint8_t byte) {
  return uint8_t(8 - popcount(byte));
}

template<typename N0, typename N1>
inline
int ith_bit(N0 n, N1 i) {
  return (n & ( N1(1) << i )) >> i;
}

template<typename N>
bool bounded_values_in_uint(N x, uint8_t b, uint8_t initial) {
  int adj_ones = initial;
  static_assert(sizeof(N) <= 32, "invalid size");
  for (uint8_t i = 0; i < 8 * sizeof(N); ++i) {
    if (ith_bit(x, i) == 0) {
      if (adj_ones > b) {
        return false;
      }
      adj_ones = 0;
    } else {
      ++adj_ones;
    }
  }
  return true;
}

void shuffle_and_store(const uint8_t* src, sgl::shuffle<16> shuffle, uint8_t* dst) {
  aligned16byte_t r = load_unaligned128(src);
  shuffle_and_store128(r, *shuffle.ptr, dst);
  shuffle_and_store128(r, *(shuffle.ptr + 1), dst + 16);
}

template<typename GroupFormat>
struct construct_shuffle_sequence : GroupFormat {
  void operator()(typename GroupFormat::descriptor_type desc, uint8_t state, int8_t* shf) {
    std::fill_n(shf, GroupFormat::shuffle_size, -1);

    if (!this->valid_table_entry(desc, state)) {
      return;
    }

    uint8_t j = 0;
    uint8_t s = 4 - state;
    for (uint8_t i = 0; i < this->num(desc); ++i) {
      for (uint8_t n = 0; n < s; ++n, ++shf) {
        if (n < this->len(desc, i)) {
          *shf = j++;
        }
      }
      s = 4;
    }

    for (uint8_t n = 0; n < this->rem(desc); ++n) {
      *shf++ = j++;
    }
  }
};

template<typename GroupFormat>
construct_shuffle_sequence<GroupFormat>& cast_to_shuffle_builder(GroupFormat* f) {
  return static_cast<construct_shuffle_sequence<GroupFormat>&>(*f);
}

struct empty_type {
  empty_type() {}

  template<typename T>
  explicit empty_type(const T&) {}

  empty_type& operator=(const empty_type&) {
    return *this;
  }
}; // struct empty_type

struct varint_gb_format {
  typedef sgl::shuffle<16> shuffle_sequence_type;
  typedef uint8_t descriptor_type;
  typedef uint8_t info_type;
  typedef sgl::empty_type state_type;

  aligned16byte_t shuffles[256];
  uint8_t input_offsets[256];

  shuffle_sequence_type lookup_shuffle(descriptor_type desc, state_type state) {
    return shuffle_sequence_type(&shuffles[desc]);
  }

  uint8_t lookup_info(descriptor_type desc, state_type) {
    return input_offsets[desc];
  }

  ptrdiff_t input_offset(info_type x) {
    return ptrdiff_t(x);
  }

  ptrdiff_t output_offset(info_type) {
    return 16;
  }

  state_type next_state(info_type) {
    return state_type();
  }

  static const constexpr size_t shuffle_size = shuffle_sequence_type::shuffle_size;

  bool valid_table_entry(descriptor_type, uint8_t state_value) {
    return state_value == 0;
  }

  uint8_t num(descriptor_type desc) {
      return 4;
  }

  uint8_t len(descriptor_type desc, uint8_t i) {
    return ((desc >> (2 * i)) & 0x03) + 1;
  }

  uint8_t rem(descriptor_type d) {
    return len(d, 0) + len(d, 1) + len(d, 2) + len(d, 3) + 1;
  }

  uint8_t offset(descriptor_type d) {
    return len(d, 0) + len(d, 1) + len(d, 2) + len(d, 3) + 1;
  }

  varint_gb_format() {
    auto shuffle_builder = cast_to_shuffle_builder(this);
    for (int i = 0; i < 256; ++i) {
      input_offsets[i] = offset(descriptor_type(i));
      shuffle_builder(descriptor_type(i), 0, (int8_t*)(shuffles + i));
    }
  }
}; // struct varint_gb_format

struct varint_g8iu_format {
  typedef shuffle<32> shuffle_sequence_type;
  typedef uint8_t descriptor_type;
  typedef uint8_t info_type;
  typedef empty_type state_type;

  aligned16byte_t shuffles[256][2];
  uint8_t output_offsets[256];

  shuffle_sequence_type lookup_shuffle(descriptor_type desc, state_type state) {
    return shuffle_sequence_type(shuffles[desc]);
  }

  uint8_t lookup_info(descriptor_type desc, state_type) {
    return output_offsets[desc];
  }

  ptrdiff_t input_offset(info_type) {
    return 9; // size of data block + 1 for descritptor
  }

  ptrdiff_t output_offset(info_type r) {
    return ptrdiff_t(r);
  }

  state_type next_state(info_type) {
    return state_type();
  }

  // Building the table
  static const constexpr size_t shuffle_size = shuffle_sequence_type::shuffle_size;

  bool valid_table_entry(descriptor_type desc, uint8_t state_value) {
    // A descriptor is invalid if it contains more than three 1 bits
    // followed by a 0 bit (where we order the bits from lsb to msb)
    if (state_value != 0) return false;
    return bounded_values_in_uint(desc, 3, 0);
    // return state_value == 0 && bounded_values_in_uint(desc, 3, 0);
  }

  uint8_t num(descriptor_type desc) {
    return number_of_zeros_in_byte(desc);
  }

  uint8_t prior_len(descriptor_type desc, uint8_t i) {
    if (i == 0) {
      return 0;
    } else {
      uint8_t p = prior_len(desc, i - 1);
      return count_trailing_ones(desc >> p) + p + 1;
    }
  }

  uint8_t len(descriptor_type desc, uint8_t i) {
    return count_trailing_ones(desc >> prior_len(desc, i)) + 1;
  }

  uint8_t rem(descriptor_type) {
    return 0;
  }

  varint_g8iu_format() {
    auto& shuffle_builder = cast_to_shuffle_builder(this);
    for (int i = 0; i < 256; ++i) {
      output_offsets[i] = 4 * num(descriptor_type(i));
      shuffle_builder(descriptor_type(i), 0, (int8_t*)(shuffles + i));
    }
  }
}; // struct varint_g8iu_format

struct varint_g8cu_format {
  typedef shuffle<32> shuffle_sequence_type;
  typedef uint8_t descriptor_type;
  typedef uint16_t state_type;

  typedef struct offset_and_state {
    uint8_t output_offset;
    state_type next_state;
  }* info_type;

  aligned16byte_t shuffles[256 * 4][2];
  offset_and_state infos[256 * 4];

  shuffle_sequence_type lookup_shuffle(descriptor_type desc, state_type state) {
    return shuffle_sequence_type(shuffles[state | desc]);
  }

  info_type look_info(descriptor_type desc, state_type state) {
    return infos + (state | desc);
  }

  ptrdiff_t input_offset(info_type) {
    return 9;
  }

  ptrdiff_t output_offset(info_type x) {
    return ptrdiff_t(x->output_offset);
  }

  state_type next_state(info_type x) {
    return x->next_state;
  }

  static const constexpr size_t shuffle_size = shuffle_sequence_type::shuffle_size;

  bool valid_table_entry(descriptor_type desc, uint8_t state_value) {
    if (state_value > 3) {
      return false;
    }
    return bounded_values_in_uint(desc, 3, state_value);
  }

  uint8_t num(descriptor_type desc) {
    return number_of_zeros_in_byte(desc);
  }


  uint8_t prior_len(descriptor_type desc, uint8_t i) {
    if (i == 0) {
      return 0;
    } else {
      uint8_t p = prior_len(desc, i - 1);
      return count_leading_ones(desc >> p) + p + 1;
    }
  }

  uint8_t len(descriptor_type desc, uint8_t i) {
    return count_trailing_ones(desc >> prior_len(desc, i)) + 1;
  }

  uint8_t rem(descriptor_type desc) {
    return leading_ones_in_byte(desc);
  }

  varint_g8cu_format() {
    auto shuffle_builder = cast_to_shuffle_builder(this);
    for (int i = 0; i < 256; ++i) {
      for (uint8_t j = 0; j < 4; ++j) {
        descriptor_type d(i);
        uint16_t idx = ((j << 8) | d);
        infos[idx].output_offset = 4 * num(d) + rem(d) - j;
        infos[idx].next_state = (rem(d) << 8);
        shuffle_builder(d, j, (int8_t*)(shuffles[idx]));
      }
    }
  }
};
} // namespace sgl  
