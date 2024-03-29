
#pragma once

#include "mir/mir_macros.hpp"
#include <span>

/**************************************************************************************************/
#define GENERATE_BODY()                                                                            \
    using super = this_type;                                                                       \
    DECLARE_TYPE()                                                                                 \
    GENERATE_REFLECTION()                                                                          \
    inline static ivd::type* static_type()                                                         \
    {                                                                                              \
        static ivd::native_type instance(this_type::native_type());                                \
        return &instance;                                                                          \
    }                                                                                              \
                                                                                                   \
public:                                                                                            \
    this_type& operator=(this_type const&) = delete;                                               \
    this_type& operator=(this_type&&)      = delete;

/**************************************************************************************************/
