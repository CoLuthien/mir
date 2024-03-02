
module;

#include <cstddef>

export module mir.property:impl;

import :helper;
import :info;

export namespace mir
{

class property final
{
private:
    pp::handle const* const m_handle;

private:
    constexpr property(pp::handle const* handle) : m_handle(handle) {}

public:
    template <class Owner, std::size_t Index>
    static consteval auto reflect()
    {
        using info_type = pp::instance<Owner, Index>;
        return property(static_cast<pp::handle const*>(info_type::info()));
    }

public:
    template <class V>
    V get(void* obj) const
    {
        auto ptr = static_cast<pp::interface<V> const*>(m_handle);
        return ptr->get(obj);
    }

    template <class V>
    void set(void* obj, V value) const
    {
        auto ptr = static_cast<pp::interface<V> const*>(m_handle);
        return ptr->set(obj, value);
    }
};

} // namespace mir