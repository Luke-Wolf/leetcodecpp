//
// Handles Problem 2: Add Two Numbers
//

#include "add_two_numbers.h"
#include <gsl/assert>

auto AddTwoNumbers::addTwoNumbers(const ListNode *list_1, const ListNode *list_2) -> const ListNode * {
    Expects(list_1);
    Expects(list_2);
    bool carry = false;
    ListNode *result = nullptr;
    ListNode *current = nullptr;
    while (list_1 || list_2 || carry) {
        if (carry && !list_1 && !list_2) {
            current->next = new ListNode(1);
            carry = false;
        } else if (!list_1) {
            //if we've run out of one list check carry and then finish out the rest;
            if (carry) {
                int value = list_2->val + 1;
                carry = value >= 10;
                if (carry) {
                    value -= 10;
                }
                current->next = new ListNode(value);
            } else {
                current->next = new ListNode(list_2->val);
            }
            current = current->next;
            list_2 = list_2->next;

        } else if (!list_2) {
            //same for above just the other list
            if (carry) {
                int value = list_1->val + 1;
                carry = value >= 10;
                if (carry) {
                    value -= 10;
                }
                current->next = new ListNode(value);
            } else {
                current->next = new ListNode(list_1->val);
            }
            current = current->next;
            list_1 = list_1->next;
        } else {
            //normal case
            int value = (carry) ? list_1->val + list_2->val + 1 : list_1->val + list_2->val;
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
            list_1 = list_1->next;
            list_2 = list_2->next;
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