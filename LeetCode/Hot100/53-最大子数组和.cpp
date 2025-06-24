//
// Created by alpha on 2025/6/24.
//

#include <iostream>
#include <vector>
using namespace std;


// 优化：分治法
// 分解（Divide）：将问题划分成更小的子问题（本题：将数组一分为二）。
// 解决（Conquer）：递归地解决每个子问题（本题：递归找到左右部分的最大子数组和）。
// 合并（Combine）：将子问题的答案合并得到原问题的答案（本题：比较左边最大、 右边最大、 横跨中点最大）。
// 有机会再说（懒一下




// self: 100%-63.46%
class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int size = nums.size();
        if (size == 1) return nums[0];

        int max_sum = nums[0];

        int curr_max = nums[0];

        for (int i = 1; i < size; i++) {
            curr_max = nums[i] > curr_max + nums[i] ? nums[i] : curr_max + nums[i];
            max_sum = max_sum > curr_max ? max_sum : curr_max;
        }
        return max_sum;
    }
};


