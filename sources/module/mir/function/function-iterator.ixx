
module;

#include <tuple>
#include <cstddef>
#include <string_view>
#include <limits>

export module mir.function:iterator;

import :impl;
import :helper;

export namespace mir
{

template <class Target, std::size_t Index>
struct fn_iterate
{
    static constexpr auto instance = function::reflect<Target, Index>();
    static constexpr auto name     = fn::name<Target, Index>;
    static constexpr auto pair     = std::make_pair(name, const_cast<function*>(&instance));
    static constexpr std::pair<std::string_view, function*> get_entry() { return pair; }
};

template <class Target>
struct fn_iterate<Target, std::numeric_limits<std::size_t>::max()>
{
    static constexpr std::pair<std::string_view, function*> get_entry()
    {
        return std::pair<std::string_view, function*>{};
    }
};

template <class Target, class ResultType, class... Args>
consteval auto
take_function_type(ResultType (Target::*Ptr)(Args...))
{
    return decltype(Ptr){};
}

template <class Target, class ResultType, class... Args>
consteval auto
take_function_type(ResultType (Target::*const Ptr)(Args...) const)
{
    return decltype(Ptr){};
}

template <class Target, class ResultType, class... Args>
consteval auto
take_function_type(ResultType Ptr(Args...))
{
    return decltype(Ptr){};
}

} // namespace mir
