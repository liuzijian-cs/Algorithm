//
// Created by alpha on 2025/6/24.
//


// 思路：
// 输入：nums = [1,5,11,5]
// 输出：true
// 解释：数组可以分割成 [1, 5, 5] 和 [11] 。
// 首先遍历，获取数组总和sum比如等于22
// 然后因为分为两个子集，所以必须是偶数，奇数直接false
// 这样一半就是11
// 如果最大值超过了11，false
//
// emm剩下的不太知道了

// 思路分析 (Analysis)

// 你的前半部分思路完全正确：
// ✅ 计算总和并检查是否为偶数 (Calculate total sum and check if even)
// ✅ 检查最大值是否超过目标值 (Check if max value exceeds target)

// 接下来的关键思路是：这本质上是一个0/1背包问题 (This is essentially a 0/1 knapsack problem)
//
// 背包容量：sum/2 (Knapsack capacity: sum/2)
// 物品：数组中的每个元素 (Items: each element in array)
// 目标：能否恰好装满背包 (Goal: can we fill the knapsack exactly)

// 最优解法：动态规划 (Optimal Solution: Dynamic Programming)


#include <iostream>
#include <vector>
using namespace std;

// 41.86% - 90.34%
class Solution {
public:
    bool canPartition(vector<int> &nums) {
        if (nums.empty() || nums.size() == 1) return false;

        // Calculate the total sum of the array
        int sum = 0;
        int max = INT_MIN;
        for (const int num: nums) {
            sum += num;
            max = max > num ? max : num;
        }

        // If sum is odd, can not partition into two equal subsets:
        if (sum % 2 != 0) return false;

        int target = sum / 2;
        if (max > target) return false; // If max element is greater than target, cannot partition
        if (max == target) return true; // If max element equals target, return true directly

        // Dynamic Programming: dp[i] represents whether we can form a subset with sum i
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        // Iterate through each number
        for (const int num: nums) {
            for (int j=target;j>=num;j--) {
                dp[j] = dp[j] || dp[j-num];
            }
        }
        // 1 5 5 11
        // 0 1 2 3 4 5 6 7 8 9 10 11
        // T F F F F F F F F F F  F
        // T T F F F F F F F F F  F 1
        // T T F F F T T F F F F  F 5
        // T T F F F T T F F F F  T 5 accept
        return dp[target];
    }
};
