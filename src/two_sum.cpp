//
// Handles Problem 1: Two Sum
//
#include "two_sum.h"
#include <gsl/assert>
#include <vector>

auto TwoSum::twoSum(const std::vector<int> &nums, const int target) -> std::vector<int> {
    Expects(nums.size() >= 2);
    Expects(nums.size() <= 100000);
    Expects(target >= -1000000000);
    Expects(target <= 1000000000);
    //Expensive to check but also
    //-10^9 <= nums.at(i) <= 10^9
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            if (nums.at(i) + nums.at(j) == target) {
                return {i, j};
            }
        }
    }
    return {};
}