//
// Handles Problem 1: Two Sum
//
#include <catch.hpp>
#include <vector>
#include "two_sum.h"

TEST_CASE("Two Sum, Example 1") {
    std::vector<int> const input = { 2,7,11,15};
    auto result = TwoSum::twoSum(input, 9);
    REQUIRE(result.at(0) == 0);
    REQUIRE(result.at(1) == 1);
}

TEST_CASE("Two Sum, Example 2") {
    std::vector<int> const input = { 3,2,4};
    auto result = TwoSum::twoSum(input, 6);
    REQUIRE(result.at(0) == 1);
    REQUIRE(result.at(1) == 2);
}

TEST_CASE("Two Sum, Example 3") {
    std::vector<int> const input = { 3,3 };
    auto result = TwoSum::twoSum(input, 6);
    REQUIRE(result.at(0) == 0);
    REQUIRE(result.at(1) == 1);
}