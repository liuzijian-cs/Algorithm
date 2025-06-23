//
// Created by alpha on 2025/6/23.
//


// 思路：
// 感觉像是一个贪心或动态规划问题
//
// 由于结果是计算乘积，因此我初步将数据分为 + 0 -数三部分（当然，我想这里并不重要）；
//
// 问题在于如何获得最大的乘积
//
// 我觉得可以贪心一些，
//
// 首先分配一个dp数组，
// dp[0]=nums[0]
//
// 从第一个位置开始遍历，如果加入下一个数后乘积是增长的（连续的正数一定增长，），则将结果放在dp[i],如果减小则emm
//
// 没太想好

// 分析：
// 你的初步思路是对的，这确实是一个动态规划问题。但是仅仅考虑正数增长是不够的，因为：
// 负数乘以负数会变成正数*
// 当前的最小值可能因为遇到负数而变成最大值***
// 因此，我们需要同时维护两个状态：
// maxDP[i]：以位置i结尾的子数组的最大乘积；
// minDP[i]：以位置i结尾的子数组的最小乘积；

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 完全不需要DP数组：100% - 94.19%
class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int result = INT_MIN;
        int max = 1;
        int min = 1;
        for (int num: nums) {
            if (num<0) {
                int tmp = max;
                max = min;
                min = tmp;
            }
            max = max * num > num ? max * num : num;
            min = min * num < num ? min * num : num;

            result = max > result ? max : result;
        }
        return result;
    }
};

// 21.58%-30.27%
class Solution {
public:
    int maxProduct(vector<int> &nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        if (n == 1) return nums[0];

        // Initialise dynamic programming arrays:
        // maxDP[i] represents the maximum product of subarray ending at position i:
        vector<int> maxDP(n);
        // minDP[i] represents the minimum product of subarray ending at position i:
        vector<int> minDP(n);

        // Initial state:
        maxDP[0] = nums[0];
        minDP[0] = nums[0];
        int result = nums[0];

        // Dynamic programming state transition:
        for (int i = 1; i < n; i++) {
            if (nums[i] > 0) {
                maxDP[i] = max(nums[i], maxDP[i - 1] * nums[i]);
                minDP[i] = min(nums[i], minDP[i - 1] * nums[i]);
            } else if (nums[i] < 0) {
                maxDP[i] = max(nums[i], minDP[i - 1] * nums[i]);
                minDP[i] = min(nums[i], maxDP[i - 1] * nums[i]);
            } else {
                maxDP[i] = minDP[i] = 0;
            }
            // 每一步都更新最大值
            result = max(result, maxDP[i]);
        }
        return result;
    }
};
