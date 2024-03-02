
module;

#include <limits>
#include <cstddef>
#include <tuple>
#include <string_view>

export module mir.property:iterator;

import :helper;
import :info;
import :impl;

export namespace mir
{
template <class Target, std::size_t Index>
struct pp_iterate
{
    static constexpr auto             instance = property::reflect<Target, Index>();
    static constexpr std::string_view name     = pp::name<Target, Index>;
    static constexpr auto             pair = std::make_pair(name, const_cast<property*>(&instance));
    static constexpr std::pair<std::string_view, property*> get_entry() { return pair; }
};

template <class Target>
struct pp_iterate<Target, std::numeric_limits<std::size_t>::max()>
{
    static constexpr std::pair<std::string_view, property*> get_entry() { return {}; }
};

} // namespace mir
