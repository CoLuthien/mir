
#pragma once

#include "fn_macros.hpp"
#include "pp_macros.hpp"
#include "type_macros.hpp"

#include <source_location>
#include <cstddef>

#define GENERATE_TYPE_INFO()                                                                       \
    static inline mir::type* native_type()                                                         \
    {                                                                                              \
        static constexpr auto type_name  = std::source_location::current().function_name();        \
        static constexpr auto functions  = reflected_functions();                                  \
        static constexpr auto properties = reflected_properties();                                 \
        static constexpr auto fn_span    = std::span{functions.data(), functions.size()};          \
        static constexpr auto pp_span    = std::span{properties.data(), properties.size()};        \
        static mir::type      instance{type_name, fn_span, pp_span};                               \
        return &instance;                                                                          \
    }

/**************************************************************************************************/

#define GENERATE_REFLECTION()                                                                      \
public:                                                                                            \
    template <std::size_t>                                                                         \
    struct mir_property;                                                                           \
    template <std::size_t>                                                                         \
    struct mir_function;                                                                           \
                                                                                                   \
private:                                                                                           \
    GENERATE_FUNCTION_INFO()                                                                       \
    GENERATE_PROPERTY_INFO()                                                                       \
public:                                                                                            \
    GENERATE_TYPE_INFO()

/**************************************************************************************************/
