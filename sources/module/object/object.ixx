
module;

#include "object_api.hpp"
#include "mir/mir_macros.hpp"

#include <functional>
#include <string_view>
#include <string>
#include <unordered_map>

export module ivd.object:object;

import mir;
import ivd.object.type;

export namespace ivd
{
class OBJECT_API object : public field
{
public:
    using this_type = object;

private:
};

} // namespace ivd