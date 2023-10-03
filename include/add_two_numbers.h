//
// Handles Problem 2: Add Two Numbers
//

#ifndef LEETCODECPP_ADD_TWO_NUMBERS_H
#define LEETCODECPP_ADD_TWO_NUMBERS_H

#include <initializer_list>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class AddTwoNumbers {
public:
    static auto generateList(std::initializer_list<int> input) -> ListNode *;

    static auto addTwoNumbers(const ListNode *list_1, const ListNode *list_2) -> const ListNode *;
};


#endif //LEETCODECPP_ADD_TWO_NUMBERS_H
