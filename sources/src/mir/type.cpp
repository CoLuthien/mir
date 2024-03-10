

module;
#include <string_view>

module mir.type;

import mir.function;
import mir.property;

namespace mir
{
function const*
type::find_fn(std::string_view name) const
{
    if (m_fnmap.contains(name))
    {
        return m_fnmap.at(name);
    }
    return nullptr;
}

mir::property const*
type::find_pp(std::string_view name) const
{
    if (m_ppmap.contains(name))
    {
        return m_ppmap.at(name);
    }

    return nullptr;
}

} // namespace ivd::mir