
module;

#include "object_api.hpp"

#include <string_view>
#include <cstddef>

export module ivd.object:type;

export import mir;

import ivd.core;

import :object;

export namespace ivd
{

class OBJECT_API type
{
public:
    virtual std::size_t      size() const     = 0;
    virtual std::string_view name() const     = 0;
    virtual void*            allocate() const = 0;
};

} // namespace ivd