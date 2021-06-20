#pragma once
#include <memory>
#include <type_traits>
#include <cstring>
#include <smmintrin.h>
#include "macros.h"
#include "sgl.v1.function.transform_positions.h"

#include "sgl.v1.struct.default_tag.h"
#include "sgl.v1.struct.is_nothrow_copyable.h"
#include "sgl.v1.struct.is_nothrow_movable.h"
#include "sgl.v1.struct.is_nothrow_algorithm.h"
#include "sgl.v1.function.load_unaligned.h"
#include "sgl.v1.function.repeat_n.h"
#include "sgl.v1.struct.totally_ordered.h"
#include "sgl.v1.struct.triple.h"
#include "sgl.v1.function.min.h"
#include "sgl.v1.function.repeat_n.h"
#include "sgl.v1.function.construct.h"
#include "sgl.v1.function.uninitialized_construct.h"
#include "sgl.v1.function.destruct.h"

#include <immintrin.h>
#include "sgl.v1.struct.simd_tag.h"
#include "sgl.v1.function.copy_elements.h"
#include "sgl.v1.function.copy.h"
#include "sgl.v1.function.uninitialized_copy_construct.h"

#include "sgl.v1.function.uninitialized_copy.h"
#include "sgl.v1.function.max.h"
#include "sgl.v1.function.alignment_padding.h"
#include "sgl.v1.function.stream_aligned.h"
#include "sgl.v1.function.fill.h"
#include "sgl.v1.function.uninitialized_fill.h"
#include "sgl.v1.function.uninitialized_fill_n.h"
#include "sgl.v1.function.transform.h"
#include "sgl.v1.function.uninitialized_transform.h"

#include "sgl.v1.function.copy_range_value_range.h"
#include "sgl.v1.function.move_range_value_range.h"
#include "sgl.v1.function.uninitialized_copy_range_value_range.h"
#include "sgl.v1.function.uninitialized_move_range_value_range.h"
#include "sgl.v1.struct.is_nothrow_semiregular.h"
#include "sgl.v1.function.copy_bounded.h"
#include "sgl.v1.function.uninitialized_move.h"
#include "sgl.v1.function.default_construct.h"
#include "sgl.v1.function.uninitialized_default_construct.h"
#include "sgl.v1.function.uninitialized_move_range_value_range.h"
#include "sgl.v1.function.equal.h"
#include "sgl.v1.struct.totally_ordered.h"
#include "sgl.v1.function.multiplicative_resize.h"
#include "sgl.v1.class.array.h"
