//
// Handles Problem 2: Add Two Numbers
//
#include <catch.hpp>
#include "add_two_numbers.h"

TEST_CASE("Generate List: 1 element: {0}") {
    const auto *list = AddTwoNumbers::generateList({0});
    REQUIRE(list != nullptr);
    REQUIRE(!list->next);
    REQUIRE(list->val == 0);
    delete list;
}

TEST_CASE("Generate List: 3 elements: {1,2,3}") {
    const auto *list = AddTwoNumbers::generateList({1, 2, 3});
    REQUIRE(list != nullptr);
    REQUIRE(list->val == 1);
    REQUIRE(list->next);
    REQUIRE(list->next->val == 2);
    REQUIRE(list->next->next);
    REQUIRE(list->next->next->val == 3);
    REQUIRE(!list->next->next->next);
    delete list;
}

TEST_CASE("Add Two Numbers Example 1 342 + 465 = 807") {
    const auto *list_1 = AddTwoNumbers::generateList({2, 4, 3});
    REQUIRE(list_1 != nullptr);
    const auto *list_2 = AddTwoNumbers::generateList({5, 6, 4});
    REQUIRE(list_2 != nullptr);
    const auto *result = AddTwoNumbers::addTwoNumbers(list_1, list_2);
    REQUIRE(result != nullptr);
    REQUIRE(result->val == 7);
    REQUIRE(result->next);
    REQUIRE(result->next->val == 0);
    REQUIRE(result->next->next);
    REQUIRE(result->next->next->val == 8);
    REQUIRE(!result->next->next->next);
    delete list_1;
    delete list_2;
    delete result;
}

TEST_CASE("Add Two Numbers Example 2: 0 + 0 = 0") {
    const auto *list_1 = AddTwoNumbers::generateList({0});
    REQUIRE(list_1);
    const auto *list_2 = AddTwoNumbers::generateList({0});
    REQUIRE(list_2);
    const auto *result = AddTwoNumbers::addTwoNumbers(list_1, list_2);
    REQUIRE(result);
    REQUIRE(result->val == 0);
    REQUIRE(!result->next);
    delete list_1;
    delete list_2;
    delete result;
}

TEST_CASE("Add two Numbers Example 3: 9,999,999 + 9,999 = 10,009,998") {
    const auto *list_1 = AddTwoNumbers::generateList({9, 9, 9, 9, 9, 9, 9});
    REQUIRE(list_1);
    const auto *list_2 = AddTwoNumbers::generateList({9, 9, 9, 9});
    REQUIRE(list_2);
    const auto *result = AddTwoNumbers::addTwoNumbers(list_1, list_2);
    REQUIRE(result);
    REQUIRE(result->val == 8);
    REQUIRE(result->next);
    REQUIRE(result->next->val == 9);
    REQUIRE(result->next->next);
    REQUIRE(result->next->next->val == 9);
    REQUIRE(result->next->next->next);
    REQUIRE(result->next->next->next->val == 9);
    REQUIRE(result->next->next->next->next);
    REQUIRE(result->next->next->next->next->val == 0);
    REQUIRE(result->next->next->next->next->next);
    REQUIRE(result->next->next->next->next->next->val == 0);
    REQUIRE(result->next->next->next->next->next->next);
    REQUIRE(result->next->next->next->next->next->next->val == 0);
    REQUIRE(result->next->next->next->next->next->next->next);
    REQUIRE(result->next->next->next->next->next->next->next->val == 1);
    REQUIRE(!result->next->next->next->next->next->next->next->next);
    delete list_1;
    delete list_2;
    delete result;
}