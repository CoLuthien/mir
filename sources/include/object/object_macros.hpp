
#pragma once

#include "mir/mir_macros.hpp"
#include <span>

#define GENERATE_CLASS_INFO()                                                                      \
    static constexpr auto functions  = reflected_functions();                                      \
    static constexpr auto properties = reflected_properties();                                     \
    static constexpr auto fn_span    = std::span{functions.data(), functions.size()};              \
    static constexpr auto pp_span    = std::span{properties.data(), properties.size()};

/**************************************************************************************************/

#define GENERATE_BODY()                                                                            \
    using super = this_type;                                                                       \
    DECLARE_TYPE()                                                                                 \
    GENERATE_REFLECTION()                                                                          \
    using ancester_list = mir::list::push_front<super::ancester_list, this_type>;                  \
                                                                                                   \
public:                                                                                            \
    static ivd::pclass* static_class()                                                             \
    {                                                                                              \
        GENERATE_CLASS_INFO()                                                                      \
        static ivd::pclass instance(super::static_class(), fn_span, pp_span);                      \
        return &instance;                                                                          \
    }                                                                                              \
                                                                                                   \
public:                                                                                            \
    this_type& operator=(this_type const&) = delete;                                               \
    this_type& operator=(this_type&&)      = delete;

/**************************************************************************************************/

#define DECLARE_POBJECT()                                                                          \
public:                                                                                            \
    using super         = pobject;                                                                 \
    using this_type     = pobject;                                                                 \
    using ancester_list = mir::typelist<this_type>;                                                \
                                                                                                   \
public:                                                                                            \
    GENERATE_REFLECTION()                                                                          \
                                                                                                   \
public:                                                                                            \
    pobject(pobject const&)                       = delete;                                        \
    pobject(pobject&&)                            = delete;                                        \
    pobject&            operator=(pobject const&) = delete;                                        \
    pobject&            operator=(pobject&&)      = delete;                                        \
    static ivd::pclass* static_class();
