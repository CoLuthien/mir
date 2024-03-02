
module;

#include <cstddef>
#include <limits>
#include <array>

export module mir:generator;

export namespace mir
{
template <template <class, std::size_t> class Info, class Target, std::size_t Index>
    requires requires { Index > 0; }
struct generate
{
    static constexpr auto value = Info<Target, Index - 1>::get_entry();

    static constexpr auto entry_point() { return recurse(); }

    template <typename... Args>
    static constexpr auto recurse(Args const&... args)
    {
        return generate<Info, Target, Index - 1>::recurse(value, args...);
    }
};

template <template <class, std::size_t> class Info, class Target>
struct generate<Info, Target, 0>
{

    using type = decltype(Info<Target, std::numeric_limits<std::size_t>::max()>::get_entry());
    static constexpr auto entry_point() { return std::array<type, 0>{}; }
    template <typename... Args>
    static constexpr auto recurse(Args const&... args)
    {
        return std::array{args...};
    }
};

} // namespace mir