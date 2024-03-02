
module;

#include <type_traits>

export module mir.common;

export import :this_type;
export import :index;
export import :typehash;
export import :typelist;

export namespace mir::common
{
template <typename T>
concept is_iterable_type = requires {
    T::begin();
    T::end();
};

template <class, template <class...> class>
constexpr bool is_specialization = false;

template <template <class...> class T, class... Args>
constexpr bool is_specialization<T<Args...>, T> = true;

} // namespace mir::common