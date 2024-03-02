
module;

#include "object_api.hpp"
#include "object_macros.hpp"
#include "mir_macros.hpp"

#include <span>

export module ivd.object:pobject;

import mir;

export namespace ivd
{
class pclass;

class OBJECT_API pobject
{
public:
    DECLARE_POBJECT()

public:
    pobject();
    virtual ~pobject();

public:
};

} // namespace ivd
