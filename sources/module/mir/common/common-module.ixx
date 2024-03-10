
module;

#include <type_traits>

export module mir.common;

export import :typehash;
export import :index;
export import :typelist;
export import :this_type;

export namespace mir::common
{
template <typename T>
concept is_iterable_type = requires {
    T::begin();
    T::end();
};

template <class T>
concept is_reflected = requires {
    typename T::template mir_property<0>;
    typename T::template mir_function<0>;
};

template <class, template <class...> class>
constexpr bool is_specialization = false;

template <template <class...> class T, class... Args>
constexpr bool is_specialization<T<Args...>, T> = true;

} // namespace mir::common