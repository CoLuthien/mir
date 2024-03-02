
module;

#include "object_api.hpp"
#include "object_macros.hpp"
#include <unordered_map>
#include <string_view>
#include <span>

export module ivd.object:pclass;

import mir;
import :pobject;

export namespace ivd
{

class OBJECT_API pclass : public pobject
{
public:
    using fn_span_t = std::span<std::pair<std::string_view, mir::function*> const>;
    using pp_span_t = std::span<std::pair<std::string_view, mir::property*> const>;

public:
    pclass(pclass*   super_class,  //
           fn_span_t function_map, //
           pp_span_t property_map)
        : m_super(super_class),                                  //
          m_functions(function_map.begin(), function_map.end()), //
          m_properties(property_map.begin(), property_map.end())
    {
    }

public:
private:
    pclass const* const                                  m_super;
    std::unordered_map<std::string_view, mir::function*> m_functions;
    std::unordered_map<std::string_view, mir::property*> m_properties;
};

} // namespace ivd