
module;

#include <cstddef>
#include <type_traits>

export module mir.property:helper;

import mir.common;
import :enums;

export namespace mir::pp
{
template <class Owner, std::size_t I>
using info = typename Owner::template mir_property<I>;

template <class Owner, std::size_t I>
constexpr auto name = info<Owner, I>::name;

template <class Owner, std::size_t I>
constexpr auto size = info<Owner, I>::pp_size;

template <class Owner, std::size_t I>
using prop_type = typename info<Owner, I>::template prop_type<Owner>;

template <class Owner, std::size_t I>
constexpr auto pointer = info<Owner, I>::template prop_pointer<Owner>;

template <class Owner>
constexpr auto count = common::index_value<struct prop_counter_tag, Owner::template mir_property>;

} // namespace mir::pp