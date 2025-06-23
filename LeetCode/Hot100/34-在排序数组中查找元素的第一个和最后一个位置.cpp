//
// Created by alpha on 2025/6/23.
//

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// 我们基于二分查找, 我在想是否需要双left-mid-right，也就是基于不同的策略去找其左边界和右边界
class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        if (nums.empty()) return vector<int>{-1, -1};
        int left = lowerBound(nums, target);
        left = (left == nums.size() || nums[left] != target) ? -1 : left;
        int right = upperBound(nums, target) - 1;
        right = left == -1 ? -1 : right;
        return vector<int>{left, right};
    }

private:
    int lowerBound(vector<int> &nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (target > nums[mid]) left = mid + 1;
            else right = mid;
        }
        return left;
    }

    int upperBound(vector<int> &nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (target >= nums[mid]) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};

// sb version:(100% - 64.60%)
class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        if (nums.empty()) return vector<int>{-1, -1};
        // i'm sb
        auto it_left = lower_bound(nums.begin(), nums.end(), target);
        auto it_right = upper_bound(nums.begin(), nums.end(), target);

        int left_index = (it_left == nums.end() || *it_left != target) ? -1 : it_left - nums.begin();
        // int right_index = (it_right == nums.end() || *it_left != target) ? -1 : max(0, it_right - nums.begin() - 1);
        int right_index = (left_index == -1) ? -1 : it_right - nums.begin() - 1;

        return vector<int>{left_index, right_index};
    }
};
