
module;

#include "core_api.hpp"
#include <memory>

export module ivd.core:classes;

export namespace ivd
{

template <typename T>
class unique_instance
{
public:
    static T* instance();

    unique_instance(const unique_instance&)           = delete;
    unique_instance& operator=(const unique_instance) = delete;

protected:
    struct token
    {
    };
    unique_instance() {}
};

template <typename T>
T*
unique_instance<T>::instance()
{
    static const std::unique_ptr<T> instance = std::make_unique<T>(token{});
    return instance.get();
}

} // namespace ivd