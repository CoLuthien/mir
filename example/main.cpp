
#include "fn_macros.hpp"
#include "type_macros.hpp"
#include "mir_macros.hpp"
#include "object_macros.hpp"
#include <string_view>
#include <iostream>
#include <typeinfo>

import mir;
import ivd.object;

class Test : public ivd::object
{
    GENERATE_BODY()
public:
    Test(int a){};

public:
    REFLECT_FUNCTION(test, int)
    int test(int y)
    {
        std::cout << "I am Test" << '\n';
        return y;
    }
    REFLECT_FIELD(int, x)
};

int
main()
{
    auto type = Test::native_type();

    std::cout << type->type_name() << '\n';
    std::cout << type->type_id() << '\n';

    auto fn   = type->find_fn("test");
    auto pp   = type->find_pp("x");
    auto name = Test::mir_function<0>::name;

    std::cout << name << '\n';

    Test x{1};

    int a = 1;
    a     = fn->invoke<int>(static_cast<void*>(&x));

    std ::cout << a << '\n';

    return 0;
}
