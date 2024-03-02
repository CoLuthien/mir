
module;

#include <cstddef>

export module mir.common:index;

export namespace mir::common
{
template <std::size_t, class, template <std::size_t> class>
struct index_impl
{
    static constexpr std::size_t value = 0;
};

template <std::size_t I, class Tag, template <std::size_t> class Type>
    requires requires { Type<I>::name; }
struct index_impl<I, Tag, Type>
{
    static constexpr std::size_t value = 1 + index_impl<I + 1, Tag, Type>::value;
};

template <class Tag, template <std::size_t> class Type>
struct index
{
    static constexpr std::size_t value = index_impl<0, Tag, Type>::value;
};

template <class Tag, template <std::size_t> class Type>
constexpr auto index_value = index<Tag, Type>::value;

} // namespace mir::common