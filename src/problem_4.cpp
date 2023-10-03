//
// Solves Problem 4
//

#include "problem_4.h"

double Problem4::findMedianSortedArrays(const std::vector<int> &nums1, const std::vector<int> &nums2) {
    auto temp = std::vector<int>{};
    temp.reserve(nums1.size() + nums2.size());
    auto iter1 = std::begin(nums1);
    auto iter2 = std::begin(nums2);
    while (iter1 != std::end(nums1) || iter2 != std::end(nums2)) {
        if (iter1 == std::end(nums1)) {
            while (iter2 != std::end(nums2)) {
                temp.push_back(*iter2);
                ++iter2;
            }
        } else if (iter2 == std::end(nums2)) {
            while (iter1 != std::end(nums1)) {
                temp.push_back(*iter1);
                ++iter1;
            }
        } else {
            if (*iter1 > *iter2) {
                temp.push_back(*iter2);
                ++iter2;
            } else {
                temp.push_back(*iter1);
                ++iter1;
            }
        }

    }
    if (temp.size() % 2 == 1) {
        return static_cast<double>(temp.at(temp.size() / 2));
    } else {
        return (temp.at(temp.size() / 2 - 1) + temp.at(temp.size() / 2)) / 2.0;
    }

}

double find_mean(const std::vector<int> &nums1, const std::vector<int> &nums2) {
    if (nums1.empty() && nums2.empty()) {
        return 0.0;
    } else if (nums1.empty()) {
        return (*std::begin(nums2) + *(std::end(nums2) - 1)) / 2.0;
    } else if (nums2.empty()) {
        return (*std::begin(nums1) + *(std::end(nums1) - 1)) / 2.0;
    } else {
        auto begin_1 = *std::begin(nums1);
        auto last_1 = *(std::end(nums1) - 1);
        auto begin_2 = *std::begin(nums2);
        auto last_2 = *(std::end(nums2) - 1);

        return ((begin_1 + last_1) / 2.0 + (begin_2 + last_2) / 2.0) / 2.0;
    }
}