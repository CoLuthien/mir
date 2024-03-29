
module;

#include "object_api.hpp"

#include <string_view>

export module ivd.object:field;

import :type;

export namespace ivd
{

class type;

class OBJECT_API field
{
public:
    field(ivd::type* owner_type, std::string_view display_name);

public:
    virtual std::string_view id() const   = 0;
    virtual std::size_t      size() const = 0;

    inline ivd::type* owner() const { return m_owner; }

private:
    ivd::type*  m_owner;
    std::string m_id;
};

} // namespace ivd