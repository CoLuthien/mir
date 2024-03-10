
module;
#include "object_api.hpp"

#include <functional>
#include <string>
#include <string_view>

module ivd.object.type;

import mir;

namespace ivd
{

field_type::field_type(mir::type* native) //
    : m_name(native->type_name()),        //
      m_native(native),                   //
      m_id(native->type_id()),            //
      m_super(nullptr),                   //
      m_ctor()                            //
{
}

field_type::field_type(std::string_view name, field_type* super, field_ctor_t ctor_fn)
{
}

} // namespace ivd