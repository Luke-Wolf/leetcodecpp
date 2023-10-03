//
// Handles Problem 1: Two Sum
//
#pragma once
#ifndef LEETCODECPP_TWO_SUM_H
#define LEETCODECPP_TWO_SUM_H

#include <vector>

class TwoSum {
public:
    /**
     * Given an array of integers nums and an integer target,
     * return indices of the two numbers such that they add up to target.
     *
     *  You may assume that each input would have exactly one solution,
     *  and you may not use the same element twice.
     *
     *  You can return the answer in any order.
     * @param nums
     * @param target
     * @return
     */
    static auto twoSum(const std::vector<int>& nums, int target) -> std::vector<int>;
};


#endif //LEETCODECPP_TWO_SUM_H
