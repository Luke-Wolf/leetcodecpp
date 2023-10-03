//
// Handles Problem 2: Add Two Numbers
//

#include "add_two_numbers.h"
#include <gsl/assert>

auto AddTwoNumbers::addTwoNumbers(const ListNode *list_1, const ListNode *list_2) -> const ListNode * {
    Expects(list_1 != nullptr);
    Expects(list_2 != nullptr);
    bool carry = false;
    const ListNode *list_1_iter = list_1;
    const ListNode *list_2_iter = list_2;
    ListNode *result = nullptr;
    ListNode *current = nullptr;
    while (list_1_iter || list_2_iter || carry) {
        if (!list_1_iter && !result) {
            //if list_1 is empty and we're just starting take list_2
            return list_2;

        } else if (!list_2_iter && !result) {
            // if list_2 is empty and we're just starting take list_1
            return list_1;

        } else if (carry && !list_1_iter && !list_2_iter) {
            current->next = new ListNode(1);
            carry = false;
        } else if (!list_1_iter) {
            //if we've run out of one list check carry and then finish out the rest;
            if (carry) {
                int value = list_2_iter->val + 1;
                carry = value >= 10;
                if (carry) {
                    value -= 10;
                }
                current->next = new ListNode(value);
            } else {
                current->next = new ListNode(list_2_iter->val);
            }
            current = current->next;
            list_2_iter = list_2_iter->next;

        } else if (!list_2_iter) {
            //same for above just the other list
            if (carry) {
                int value = list_1_iter->val + 1;
                carry = value >= 10;
                if (carry) {
                    value -= 10;
                }
                current->next = new ListNode(value);
            } else {
                current->next = new ListNode(list_1_iter->val);
            }
            current = current->next;
            list_1_iter = list_1_iter->next;
        } else {
            //normal case
            int value = (carry) ? list_1_iter->val + list_2_iter->val + 1 : list_1_iter->val + list_2_iter->val;
            if (carry) {
                carry = false;
            }
            if (value >= 10) {
                carry = true;
                value -= 10;
            }
            if (!current) {
                result = new ListNode(value);
                current = result;
            } else {
                current->next = new ListNode(value);
                current = current->next;
            }
            list_1_iter = list_1_iter->next;
            list_2_iter = list_2_iter->next;
        }
    }

    return result;
}

auto AddTwoNumbers::generateList(const std::initializer_list<int> input) -> ListNode * {
    Expects(input.size() > 0);
    ListNode *start = nullptr;
    ListNode *current = nullptr;
    for (const auto *iter = std::begin(input); iter != std::end(input); ++iter) {
        if (iter == std::begin(input)) {
            start = new ListNode(*iter);
            current = start;
        } else {
            current->next = new ListNode(*iter);
            current = current->next;
        }
    }
    return start;
}