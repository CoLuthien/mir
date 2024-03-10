
module;

#include "object_api.hpp"

#include <functional>
#include <string_view>
#include <string>
#include <cstddef>
#include <unordered_map>

export module ivd.object.type:field;

import mir;

export namespace ivd
{
class field;

class OBJECT_API field_type
{
    using field_ctor_t = std::function<field*(field*, std::string_view)>;

private:
    std::string  m_name;
    mir::type*   m_native;
    std::size_t  m_id;
    field_type*  m_super;
    field_ctor_t m_ctor;

public:
    // c++ generated type constructor;
    explicit field_type(mir::type* native);

    // dynamically generated type;
    explicit field_type(std::string_view name, field_type* super, field_ctor_t ctor_fn);

public:
public:
    inline bool is_native() const { return m_native != nullptr; }
};

class OBJECT_API object_type : public field_type
{
public:
};

class OBJECT_API field
{
public:
    field() = default;
protected:
    field(field* owner, std::string_view name);

public:
    static field* construct(field_type* type, field* owner, std::string_view name);

private:
    field_type* m_type;
};

} // namespace ivd