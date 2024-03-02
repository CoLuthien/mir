
#pragma once

#include "fn_macros.hpp"
#include "pp_macros.hpp"
#include "type_macros.hpp"

#include <cstddef>

#define GENERATE_REFLECTION()                                                                      \
public:                                                                                            \
    template <std::size_t>                                                                         \
    struct mir_property;                                                                           \
    template <std::size_t>                                                                         \
    struct mir_function;                                                                           \
                                                                                                   \
private:                                                                                           \
    GENERATE_FUNCTION_INFO()                                                                       \
    GENERATE_PROPERTY_INFO()

/**************************************************************************************************/

