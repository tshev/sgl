#include <numeric>
#include <algorithm>
#include <type_traits>
#include <iterator>
#include <string>

// Without dependencies
#include "sgl.v1.function.successor_inplace.h"
#include "sgl.v1.class.label_enumerator.h"
#include "sgl.v1.struct.delta_square.h"
#include "sgl.v1.struct.plus.h"
#include "sgl.v1.struct.minus.h"
#include "sgl.v1.struct.totally_ordered.h"
#include "sgl.v1.struct.triple.h"
#include "sgl.v1.struct.if_else.h"
#include "sgl.v1.struct.tuple_size.h"

#include "sgl.v1.function.begin.h"
#include "sgl.v1.function.end.h"

#include "common.h"

#include "sgl.v1.function.lower_bound.h"
#include "sgl.v1.function.binary_search.h"
#include "sgl.v1.function.upper_bound.h"
#include "sgl.v1.function.accumulate.h"
#include "sgl.v1.function.accumulate_squared_diffs.h"
#include "sgl.v1.function.all.h"
#include "sgl.v1.function.any.h"
#include "sgl.v1.function.construct_ref.h"
#include "sgl.v1.function.uninitialized_construct.h"

#include "sgl.v1.function.contains_all.h"
#include "sgl.v1.function.contains.h"

#include "sgl.v1.function.copy_construct.h"
#include "sgl.v1.function.copy_cyclic.h"
#include "sgl.v1.function.destruct.h"
#include "sgl.v1.function.uninitialized_copy_construct.h"
#include "sgl.v1.function.copy.h"
#include "sgl.v1.function.copy_n.h"
#include "sgl.v1.function.copy_if.h"
#include "sgl.v1.function.copy_n_while.h"
#include "sgl.v1.function.copy_bounded.h"
#include "sgl.v1.function.copy_while.h"
#include "sgl.v1.function.copy_while_not.h"
#include "sgl.v1.function.copy_range_value_range.h"
#include "sgl.v1.function.cumulate.h"
#include "sgl.v1.function.cumulate_one.h"
#include "sgl.v1.function.uninitialized_construct.h"
#include "sgl.v1.function.uninitialized_default_construct.h"
#include "sgl.v1.function.equal_ranges.h"
#include "sgl.v1.function.equal.h"


#include "sgl.v1.function.find_adjacent.h"
#include "sgl.v1.function.find_adjacent_next.h"
#include "sgl.v1.function.find_adjacent_equivalent.h"
#include "sgl.v1.function.find_adjacent_equivalent_unguarded.h"
#include "sgl.v1.function.find_adjacent_equivalent_last.h"
#include "sgl.v1.function.find_adjacent_not_equivalent_unguarded.h"
#include "sgl.v1.function.find_adjacent_not_equivalent.h"


#include "sgl.v1.function.find.h"
#include "sgl.v1.function.for_each_split.h"
#include "sgl.v1.function.find_not_backward.h"
#include "sgl.v1.function.find_backward.h"
#include "sgl.v1.function.find_not.h"
#include "sgl.v1.function.find_nth_match.h"
#include "sgl.v1.function.find_nth_missmatch.h"

#include "sgl.v1.function.find_if.h"
#include "sgl.v1.function.find_if_inplace.h"
#include "sgl.v1.function.find_if_not.h"
#include "sgl.v1.function.find_if_inplace.h"
#include "sgl.v1.function.find_if_position_inplace.h"
#include "sgl.v1.function.find_missmatch.h"
#include "sgl.v1.function.find_missmatch_bounded.h"
#include "sgl.v1.function.find_with_sentinel_ref.h"

#include "sgl.v1.function.find_adjacent_unguarded.h"
#include "sgl.v1.function.find_adjacent_missmatch.h"
#include "sgl.v1.function.find_adjacent_missmatch_unguarded.h"

#include "sgl.v1.function.first_predecessor_unguarded.h"
#include "sgl.v1.function.first_predecessor.h"
#include "sgl.v1.function.first_predecessor_action_unguarded.h"
#include "sgl.v1.function.first_predecessor_action.h"
#include "sgl.v1.function.first_predecessor_transformation_unguarded.h"
#include "sgl.v1.function.first_predecessor_transformation.h"
#include "sgl.v1.function.for_each.h"
#include "sgl.v1.function.for_each_block.h"
#include "sgl.v1.function.for_each_subrange.h"
#include "sgl.v1.function.sort_delimited_subranges.h"
#include "sgl.v1.function.sort_partial.h"
#include "sgl.v1.function.sort_subrange.h"
#include "sgl.v1.function.sort2.h"
#include "sgl.v1.function.frequencies.h"
#include "sgl.v1.function.frequencies_bs.h"
#include "sgl.v1.function.frequency_pairs.h"
#include "sgl.v1.function.frequency_pairs_bs.h"
#include "sgl.v1.function.generate_bm.h"
#include "sgl.v1.function.generate.h"
#include "sgl.v1.function.gini.h"
#include "sgl.v1.function.is_alpha.h"
#include "sgl.v1.function.is_space.h"
#include "sgl.v1.function.intersection_count.h"
#include "sgl.v1.function.set_intersection_count.h"

#include "sgl.v1.function.set_union_count.h"
//#include "sgl.v1.function.union_count.h"

#include "sgl.v1.function.ilog.h"
#include "sgl.v1.function.ilog10.h"
#include "sgl.v1.function.iota.h"
#include "sgl.v1.function.half_non_negative.h"
#include "sgl.v1.function.max.h"
#include "sgl.v1.function.max_iterator.h"
#include "sgl.v1.function.median_element.h"
#include "sgl.v1.gcp.h"
#include "sgl.v1.function.min.h"
#include "sgl.v1.function.min_iterator.h"
#include "sgl.v1.function.multiplicative_resize.h"
#include "sgl.v1.function.nth_predecessor_unguarded.h"
#include "sgl.v1.function.nth_predecessor.h"
#include "sgl.v1.function.orbit_length.h"
#include "sgl.v1.function.partition_copy.h"
#include "sgl.v1.function.partition_copy_position.h"
#include "sgl.v1.function.partition_transform.h"
#include "sgl.v1.function.partition_transform_position.h"
#include "sgl.v1.function.remove_if_position.h"
#include "sgl.v1.function.partition.h"
#include "sgl.v1.function.parse_int.h"
#include "sgl.v1.function.parse_uint.h"
#include "sgl.v1.function.power_semigroup.h"
#include "sgl.v1.function.reduce2ops.h"
#include "sgl.v1.function.replace.h"
#include "sgl.v1.function.replace_if.h"
#include "sgl.v1.function.rotate_leftmost.h"
#include "sgl.v1.function.rotate_rightmost.h"
#include "sgl.v1.function.shift_left.h"
#include "sgl.v1.function.split.h"
#include "sgl.v1.function.square.h"
#include "sgl.v1.function.sqrt.h"
#include "sgl.v1.function.transform_n.h"
#include "sgl.v1.function.transform_truncated.h"
#include "sgl.v1.function.transform_n_truncated.h"
#include "sgl.v1.function.transform_truncated.h"
#include "sgl.v1.function.transform_while.h"
#include "sgl.v1.function.transform_with_step.h"
#include "sgl.v1.function.transform.h"
#include "sgl.v1.function.transform_splits.h"

#include "sgl.v1.function.transform_adjacent.h"
#include "sgl.v1.function.transform_adjacent_inplace.h"

#include "sgl.v1.function.for_each_in_tuple.h"
#include "sgl.v1.function.for_each_in_tuple_while.h"
#include "sgl.v1.function.unique_count.h"
#include "sgl.v1.function.unique_squashed.h"
#include "sgl.v1.function.unique_transform.h"
#include "sgl.v1.function.uninitialized_copy_range_value_range.h"
#include "sgl.v1.function.uninitialized_move.h"
#include "sgl.v1.function.uninitialized_move_range_value_range.h"

// SECTION "type_traits"
#include "sgl.v1.struct.enable_if_forward_iterator.h"
#include "sgl.v1.struct.is_nothrow_movable.h"
#include "sgl.v1.struct.is_nothrow_semiregular.h"
#include "sgl.v1.class.pimpl.h"
#include "sgl.v1.class.enumeration.h"
//#include "sgl.v1.class.function.partition_semistable_position.h"

#include "macro_expressions.h"
#include "sgl.v1.struct.distance_type.h"
#include "sgl.v1.struct.nanoseconds.h"
#include "sgl.v1.struct.equals.h"


#include "sgl.v1.struct.error_code.h"
// #include "sgl.v1.class.shared_mutex.h"
#include "sgl.v1.reducer.struct.square_deviation.h"
#include "sgl.v1.struct.input_type.h"


#include "sgl.v1.struct.equivalent_types.h"
#include "sgl.v1.struct.pair.h"
#include "sgl.v1.struct.function_domains.h"
#include "sgl.v1.struct.increment.h"


#include "algorithm.h"
#include "sgl.v1.struct.instrumented.h"
#include "sgl.v1.class.file_descriptor.h"
#include "sgl.v1.class.mmap.h"
#include "sgl.v1.class.array_static.h"
#include "sgl.v1.struct.array_view.h"
#include "sgl.v1.class.circular_buffer.h"
#include "sgl.v1.struct.observer.h"

#include "sgl.v1.struct.transformation_iterator.h"
#include "sgl.v1.struct.stopwatch.h"
//#include "numeric.h"

// data structures
#include "sgl.v1.class.array.h"
#include "sgl.v1.class.linked_list.h"
#include "sgl.v1.class.queue.h"

#include "sgl.v1.struct.expression_separator.h"
#include "sgl.v1.function.parse_program_option.h"
#include "sgl.v1.function.parse_program_options.h"


#include "sgl.v1.function.size_cmd.h"
#include "sgl.v1.function.copy_cmd_args.h"
#include "sgl.v1.class.argparser.h"
