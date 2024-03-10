
module;

#include "mir_api.hpp"

#include <cstddef>
#include <type_traits>
#include <span>
#include <tuple>
#include <string_view>
#include <string>
#include <unordered_map>

export module mir.type;

import mir.function;
import mir.property;
import mir.common;

export namespace mir
{
class MIR_API type
{
    using fn_span_t = std::span<std::pair<std::string_view, function*> const>;
    using pp_span_t = std::span<std::pair<std::string_view, property*> const>;

public:
    type(std::string_view name, fn_span_t fn_data, pp_span_t pp_data)
        : m_name(name),                            //
          m_id(common::hash(name)),                //
          m_fnmap(fn_data.begin(), fn_data.end()), //
          m_ppmap(pp_data.begin(), pp_data.end())
    {
    }

public:
    inline std::string_view type_name() const { return m_name; }
    inline std::size_t      type_id() const { return m_id; }
    function const*         find_fn(std::string_view name) const;
    property const*         find_pp(std::string_view name) const;

private:
    std::string                                           m_name;
    std::size_t                                           m_id;
    std::unordered_map<std::string_view, function*> const m_fnmap;
    std::unordered_map<std::string_view, property*> const m_ppmap;
};

} // namespace mir