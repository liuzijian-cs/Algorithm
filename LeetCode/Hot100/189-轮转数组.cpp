//
// Created by alpha on 2025/6/25.
//

#include <iostream>
#include <vector>
using namespace std;

// 三次反转
// 1 2 3 4 | 5 6 7
// 4 3 2 1 | 7 6 5
// 5 6 7 1 2 3 4

// 100% - 89.85%
class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        if (nums.size() <= 1) return;
        k = k % nums.size();
        if (k == 0) return;

        reverse(nums, 0, nums.size() - k - 1);
        reverse(nums, nums.size() - k, nums.size() - 1);
        reverse(nums, 0, nums.size() - 1);
    }

private:
    void reverse(vector<int> &nums, int start, int end) {
        if (start < 0 || end > nums.size() - 1 || start >= end) return;
        while (start < end) {
            int tmp = nums[start];
            nums[start] = nums[end];
            nums[end] = tmp;
            start++;
            end--;
        }
    }
};
