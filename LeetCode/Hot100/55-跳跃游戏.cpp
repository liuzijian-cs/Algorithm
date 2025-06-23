//
// Created by alpha on 2025/6/23.
//

// 思路：
// 我觉得有点像DP，我们分配一个DP数组，长度为n，我们从nums的最后一个位置向前遍历，
//
// 初始状态：DP[nums.size()-1] = True

// 如果这个格子可以到最后一个格子可以到最后一个格子或加上这个数的格子为True，则为True

// 返回第一个格子的状态2

#include <iostream>
#include <vector>
using namespace std;

// 贪心 100% - 39.16%
class Solution {
public:
    bool canJump(vector<int> &nums) {
        int n = nums.size();
        int maxReach = 0;
        for (int i = 0; i < n; i++) {
            if (i > maxReach) return false;
            maxReach = maxReach > i + nums[i] ? maxReach : i + nums[i];
            if (maxReach >= n - 1) return true;
        }
        return false;
    }
};

// DP: 7.38%(n^2) - 10.19%
class Solution {
public:
    bool canJump(vector<int> &nums) {
        int size = nums.size();
        vector<bool> dp(size, false);

        dp[nums.size() - 1] = true;

        for (int i = nums.size() - 2; i >= 0; i--) {
            int maxReach = min(i + nums[i], size - 1);
            for (int j = i + 1; j <= maxReach; j++)
                if (dp[j]) {
                    dp[i] = true;
                    break;
                }
        }
        return dp[0];
    }
};
