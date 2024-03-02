
module;

#include <cstddef>
#include <type_traits>

export module mir.property:info;

import mir.common;
import :helper;

export namespace mir::pp
{
class handle
{
public:
    virtual ~handle() = default;

public:
    constexpr virtual std::size_t get_typehash() const = 0;
    constexpr virtual std::size_t get_typesize() const = 0;
};

template <typename ValueType>
class interface : public handle
{
public:
    virtual ~interface() = default;

public:
    virtual ValueType get(void* obj) const                  = 0;
    virtual void      set(void* obj, ValueType value) const = 0;
};

template <class Owner, std::size_t I>
class instance final : public interface<typename pp::info<Owner, I>::value_type>
{
public:
    using owner_t     = Owner;
    using property_t  = info<owner_t, I>::value_type;
    using const_ref_t = property_t const&;

    // we will not support reference type
    static_assert(std::is_reference_v<property_t> == false);

    // we only supports value and pointer
    static_assert(std::is_scalar_v<property_t>);

public:
    static constinit instance const field_info;
    static consteval auto           info() { return &field_info; }

public:
    static constexpr auto        size    = pp::size<owner_t, I>;
    static constexpr auto        pointer = pp::pointer<owner_t, I>;
    static constexpr auto        name    = pp::name<owner_t, I>;
    static constexpr std::size_t id      = common::type_hash<property_t>;

public:
    constexpr virtual std::size_t get_typehash() const override
    {
        return common::type_hash<pp::prop_type<owner_t, I>>;
    }
    constexpr virtual std::size_t get_typesize() const override { return size; }

    virtual property_t get(void* obj) const override
    {
        return reinterpret_cast<owner_t*>(obj)->*pointer;
    }

    virtual void set(void* obj, property_t value) const override
    {
        if constexpr (std::is_const_v<property_t>)
        {
            return;
        }
        else
        {
            reinterpret_cast<owner_t*>(obj)->*pointer = value;
        }
    }
};

template <class Owner, std::size_t I>
constinit instance<Owner, I> const instance<Owner, I>::field_info = {};
} // namespace mir::pp