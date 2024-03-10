
module;

#include <cstddef>
#include <tuple>
#include <type_traits>

export module mir.function:helper;

import mir.common;

export namespace mir::fn
{
template <class Owner, std::size_t I>
using info = typename Owner::template mir_function<I>;

template <class Owner, std::size_t I>
constexpr auto name = info<Owner, I>::name;

template <class Owner, std::size_t I>
using fn_type = typename info<Owner, I>::template fn_type<Owner>;

template <class Owner, std::size_t I>
auto const fn_pointer = info<Owner, I>::template fn_pointer<Owner>;

template <class Owner>
constexpr auto count = common::index_value<struct fn_counter_tag, Owner::template mir_function>;

template <class Type>
concept is_void_pointer = std::is_void_v<std::remove_pointer_t<Type>>;

template <class Type>
concept is_not_void_pointer = std::is_void_v<std::remove_pointer_t<Type>> == false;

template <typename T>
struct traits : traits<decltype(&T::operator())>
{
};

template <typename C, typename R, typename... Args>
struct traits<R (C::*)(Args...)> : traits<R (*)(Args...)>
{
};

template <typename C, typename R, typename... Args>
struct traits<R (C::*)(Args...) const> : traits<R (*)(Args...)>
{
};

template <typename R, typename... Args>
struct traits<R (*)(Args...)>
{
    using result_type                = R;
    static constexpr auto args_count = std::integral_constant<std::size_t, sizeof...(Args)>::value;
    using args_type                  = std::tuple<typename std::decay<Args>::type...>;
};

} // namespace mir::fn
