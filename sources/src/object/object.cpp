
module;

#include "object_macros.hpp"

#include <string_view>
#include <span>

module ivd.object:pobject;

import :pclass;
import mir;

namespace ivd
{
pobject::pobject()
{
}
pobject::~pobject() = default;

pclass*
pobject::static_class()
{
    GENERATE_CLASS_INFO()
    static ivd::pclass instance(nullptr, fn_span, pp_span);
    return &instance;
}

} // namespace ivd
