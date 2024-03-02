
#pragma once

#define REFLECT_FIELD(TYPES, NAME, ...)                                                            \
    TYPES NAME{__VA_ARGS__};                                                                       \
                                                                                                   \
    struct mir_##NAME##_property_tag;                                                              \
    static constexpr std::size_t mir_##NAME##_property_index =                                     \
        mir::common::index_value<mir_##NAME##_property_tag, mir_property>;                         \
    template <>                                                                                    \
    struct mir_property<mir_##NAME##_property_index>                                               \
    {                                                                                              \
        using value_type                          = TYPES;                                         \
        static constexpr auto             pp_size = sizeof(TYPES);                                 \
        static constexpr std::string_view name    = #NAME;                                         \
                                                                                                   \
    public:                                                                                        \
        template <class U>                                                                         \
        using prop_type = TYPES U::*;                                                              \
        template <class U>                                                                         \
        static constexpr TYPES U::*prop_pointer = &U::NAME;                                        \
    };

#define GENERATE_PROPERTY_INFO()                                                                   \
    static constexpr auto reflected_properties()                                                   \
    {                                                                                              \
        return mir::generate<mir::pp_iterate, this_type, mir::pp::count<this_type>>::              \
            entry_point();                                                                         \
    }