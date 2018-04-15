#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "test-codecov/sample.hpp"

TEST_CASE("sample")
{
    Test t;
    SECTION("headerFunction")
    {
        REQUIRE(t.headerFunction(1) == 7);
    }
    SECTION("cppFunction")
    {
        REQUIRE(t.cppFunction(5) == 6);
    }
}
