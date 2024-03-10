
module;

#include <cstdint>
#include <cstddef>
#include <string_view>
#include <source_location>

export module mir.common:typehash;

export namespace mir::common
{

inline constexpr std::size_t
fnv1a_64(char const* s, std::size_t count)
{
    return ((count ? fnv1a_64(s, count - 1) : 14695981039346656037u) ^ s[count]) * 1099511628211u;
}

inline constexpr auto
hash(std::string_view view)
{
    return fnv1a_64(view.data(), view.size());
}

template <typename T>
struct name_of
{
    static consteval std::string_view mangled_name()
    {
        return std::source_location::current().function_name();
    }
    using type = T;

    static constexpr std::string_view value = mangled_name();
};

template <class T>
constexpr auto type_hash = hash(name_of<T>::value);

} // namespace mir::common
