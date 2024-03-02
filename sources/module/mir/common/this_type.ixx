
module;

#include <type_traits>
#include <utility>

export module mir.common:this_type;


export namespace mir
{

template <typename Tag>
struct this_type_reader
{
    friend auto adl_type(this_type_reader<Tag>);
};

template <typename Tag, typename ThisType>
struct this_type_writer
{    
    friend auto adl_type(this_type_reader<Tag>) { return ThisType{}; }
};

template <typename Tag>
using read_type = std::remove_pointer_t<decltype(adl_type(std::declval<this_type_reader<Tag>>()))>;

} // namespace mir::common