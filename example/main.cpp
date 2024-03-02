
#include "fn_macros.hpp"
#include "type_macros.hpp"
#include "mir_macros.hpp"
#include "object_macros.hpp"
#include <string_view>

import mir;
import ivd.object;

class Test : public ivd::pobject
{
    GENERATE_BODY();

private:
    REFLECT_FUNCTION(test2)
    int test2() { return 0; }

    REFLECT_FIELD(int, x)
};

int
main()
{
    Test a{};
    auto ptr = Test::static_class();
}