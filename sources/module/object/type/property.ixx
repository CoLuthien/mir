
module;

#include "object_api.hpp"

#include <functional>
#include <string_view>
#include <string>

export module ivd.object.type:property;

import :field;

export namespace ivd
{

class OBJECT_API property : public field
{
};

} // namespace ivd