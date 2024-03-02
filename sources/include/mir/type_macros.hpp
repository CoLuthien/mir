
#pragma once

#define DECLARE_TYPE()                                                                             \
public:                                                                                            \
    struct type_tag;                                                                               \
    auto this_type_helper()->decltype(mir::this_type_writer<type_tag, decltype(this)>{},   \
                                      void());                                                     \
    using this_type = mir::read_type<type_tag>;