

module;

#include <cstddef>

export module mir.function:impl;

import :info;
import :helper;

export namespace mir
{
class function
{
public:
    template <class Owner, std::size_t I>
    static constexpr auto reflect();

public:
    template <typename R, typename... Args>
    R invoke(void* obj, Args... args) const;

    template <typename R, typename... Args>
    R invoke(Args... args) const;

private:
    constexpr function(fn::handle const* const handle) : m_handle(handle) {}

private:
    fn::handle const* const m_handle;
};

template <class Owner, std::size_t I>
constexpr auto
function::reflect()
{
    using trait = fn::traits<fn::fn_type<Owner, I>>;
    using info_type =
        typename fn::strip<Owner, I, typename trait::result_type, typename trait::args_type>::type;
    return function(info_type::info());
}
template <typename R, typename... Args>
R
function::invoke(void* obj, Args... args) const
{
    using type = fn::interface<R, Args...>;
    auto ptr   = static_cast<type const*>(m_handle);

    return ptr->invoke(obj, args...);
}

template <typename R, typename... Args>
R
function::invoke(Args... args) const
{
    using type = fn::interface<R, Args...>;
    auto ptr   = static_cast<type const*>(m_handle);

    return ptr->invoke(args...);
}

} // namespace mir