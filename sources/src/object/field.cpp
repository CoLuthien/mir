
module;

#include <string_view>

module ivd.object:field;

namespace ivd
{

field::field(ivd::type* owner_type, std::string_view display_name) : m_owner(owner_type)
{
}

} // namespace ivd