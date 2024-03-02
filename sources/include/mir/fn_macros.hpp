
#pragma once

#include <string_view>
#include <utility>

#define DEDUCE_RETURN_TYPE(NAME)                                                                   \
    template <class C, typename... Args>                                                           \
    using result_type = decltype(std::declval<C>().NAME(std::declval<Args>()...));

#define REFLECT_FUNCTION(NAME, ...)                                                                \
    static constexpr size_t mir_##NAME##_function_index =                                          \
        mir::common::index_value<struct mir_##NAME##_function_tag, mir_function>;                  \
    template <>                                                                                    \
    struct mir_function<mir_##NAME##_function_index>                                               \
    {                                                                                              \
        DEDUCE_RETURN_TYPE(NAME);                                                                  \
        static constexpr std::string_view name = #NAME;                                            \
        template <class Target>                                                                    \
        using fn_type = decltype(mir::take_function_type<Target,                                   \
                                                         result_type<Target, ##__VA_ARGS__>,       \
                                                         ##__VA_ARGS__>(&Target::NAME));           \
        template <class Target>                                                                    \
        inline static fn_type<Target> fn_pointer = &Target::NAME;                                  \
    };

#define GENERATE_FUNCTION_INFO()                                                                   \
    static constexpr auto reflected_functions()                                                    \
    {                                                                                              \
        return mir::generate<mir::fn_iterate, this_type, mir::fn::count<this_type>>::              \
            entry_point();                                                                         \
    }
