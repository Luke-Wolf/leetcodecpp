//
// Solves Problem 4
//

#include <catch.hpp>
#include "problem_4.h"

TEST_CASE("Example 1: [1,3] [2] == 2.0") {
    auto vec1 = {1, 3};
    auto vec2 = {2};
    REQUIRE_THAT(Problem4::findMedianSortedArrays(vec1, vec2),
                 Catch::Matchers::WithinRel(2.0, 0.001)
    );
}

TEST_CASE("Example 2: [1,2] [3,4] == 2.5") {
    auto vec1 = {1, 2};
    auto vec2 = {3, 4};
    REQUIRE_THAT(Problem4::findMedianSortedArrays(vec1, vec2),
                 Catch::Matchers::WithinRel(2.5, 0.001)
    );
}