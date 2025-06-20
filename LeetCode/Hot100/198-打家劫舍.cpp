//
// Created by alpha on 2025/6/20.
//

#include <iostream>
#include <vector>
using namespace std;

// 动态规划
// 这是一个典型的动态规划问题。核心约束是不能偷窃相邻的房屋，我们需要找到在满足这个约束条件下能获得的最大金额。

// 对于每个房屋，我们有两个选择：
// 偷窃当前房屋：那么我们不能偷窃前一个房屋，所以最大收益是 当前房屋金额 + 前两个房屋的最大收益(dp[i-2]+nums[i])
// 不偷窃当前房屋：那么最大收益就是 前一个房屋的最大收益（dp[i-1]）
// 状态转移方程：dp[i] = max(dp[i-1], nums[i] + dp[i-2])

// Example:
// [2, 7, 9, 3, 1]
// dp[0] = nums[0] = 2 // 只有一个房子，只能偷第一个。
// dp[1] = max(nums[0], nums[1]) // 偷第一个或第二个，哪个多选哪个（max(2, 7)）
// dp[2] = max(dp[1], dp[0]+nums[2]) = max(7, 2+9) = 11
// dp[3] = max(dp[2], dp[1]+nums[3]) = max(11, 7+3) = 11
// dp[4] = max(dp[3], dp[2]+nums[4]) = max(11, 11+1) = 12

class Solution {
public:
    int rob(vector<int> &nums) {
        // Boundary condition check:
        if (nums.empty())
            return 0;

        // If there's only one house, return its amount:
        if (nums.size() == 1)
            return nums[0];

        // Use two variable to optimize space complexity:
        int dp_0 = nums[0];
        int dp_1 = dp_0 > nums[1] ? dp_0 : nums[1];

        for (int i = 2; i < nums.size(); i++) {
            int current = max(dp_1, dp_0 + nums[i]);
            dp_0 = dp_1;
            dp_1 = current;
        }
        return dp_1;
    }
};
