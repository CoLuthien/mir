
module;

#include <cstddef>
#include <tuple>
#include <type_traits>
#include <functional>

export module mir.function:info;

import :helper;

export namespace mir::fn
{

class handle
{
public:
    virtual ~handle() = default;
};

template <typename R, typename... Args>
class interface : public handle
{
public:
    virtual ~interface() = default;

public:
    virtual R invoke(void* context, Args... args) const = 0;
    virtual R invoke(Args... args) const                = 0;
};

template <class Owner, std::size_t Index, typename R, typename... Args>
class instance final : public interface<R, Args...>
{
public:
    using owner_t  = Owner;
    using result_t = R;
    using info_t   = fn::info<Owner, Index>;

public:
    static constexpr auto info() { return &fn_instance; }

public:
    virtual R invoke(void* object, Args... args) const override final
    {
        if constexpr (std::is_invocable_v<fn::fn_type<Owner, Index>, owner_t, Args...>)
        {
            return std::invoke(
                fn_pointer, reinterpret_cast<owner_t*>(object), std::forward<Args>(args)...);
        }
        else
        {
            return {};
        }
    }
    virtual R invoke(Args... args) const override final
    {
        if constexpr (std::is_invocable_v<fn::fn_type<Owner, Index>, decltype(args)...>)
        {
            return std::invoke(fn_pointer, std::forward<Args>(args)...);
        }
        else
        {
            return {};
        }
    }

public:
    inline static auto const fn_pointer = fn::fn_pointer<owner_t, Index>;
    static auto constexpr name   = fn::name<owner_t, Index>;

public:
    static constinit instance const fn_instance;
};
template <class Owner, std::size_t I, typename R, typename... Args>
constinit instance<Owner, I, R, Args...> const instance<Owner, I, R, Args...>::fn_instance = {};

template <typename Target, std::size_t I, typename R, typename Tuple>
struct strip;

template <typename Target, std::size_t I, typename R, typename... Ts>
struct strip<Target, I, R, std::tuple<Ts...>>
{
    using type = instance<Target, I, R, Ts...>;
};

} // namespace mir::fn