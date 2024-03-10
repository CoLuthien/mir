
module;

#include <cstddef>
#include <span>
#include <string_view>

export module mir.property:impl;

import :helper;
export import :info;

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
    std::size_t      pp_size() const { return m_handle->pp_size(); }
    std::size_t      pp_hash() const { return m_handle->pp_hash(); }
    std::string_view pp_name() const { return m_handle->pp_name(); }

    std::span<std::byte> pp_data(void* obj) const
    {
        return std::span<std::byte>(m_handle->pp_ptr(obj), pp_size());
    }

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