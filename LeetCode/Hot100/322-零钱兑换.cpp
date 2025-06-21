//
// Created by alpha on 2025/6/21.
//

// 我的思路：
// 这是一个动态规划问题
// 边界条件：最小的硬币面值比amount大，返回0；
// amount=0返回0；

// 初始状态
// dp[0] = 0
// 状态转移 dp[i] = min(dp[i],dp[i-j]+1) 其中j从大到小遍历coins，一旦找到立即break


// 题解：
// 你的基本思路是正确的，这确实是一个经典的动态规划问题。不过有几个地方需要调整：
// 边界条件分析：
// ✅ amount = 0 返回 0 是正确的
// ❌ "最小硬币面值比amount大返回0" 这里应该返回 - 1，因为无法凑成目标金额
// 状态转移优化：
// 你提到的 "从大到小遍历coins，找到就break" 这个策略不是最优的
// 应该遍历所有可能的硬币，找到真正的最小值

// 最优解法分析：
// 这是一个完全背包问题的变种，最优解法是使用动态规划：
// 状态定义：dp[i] 表示凑成金额 i 所需的最少硬币数
// 状态转移：dp[i] = min(dp[i], dp[i-coin] + 1) 对所有可用硬币
// 时间复杂度：O(amount × coins.length)
// 空间复杂度：O(amount)


#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Dynamic Programming:
class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        // Boundary condition check:
        if (amount == 0)
            return 0;
        if (coins.empty())
            return -1;

        vector<int> dp(amount + 1, INT_MAX);

        dp[0] = 0; // 初始化

        for (int i = 1; i <= amount; i++) {
            for (int coin:coins) {
                if (coin <= i && dp[i-coin]!=INT_MAX) dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

// class Solution {
// public:
//     int coinChange(vector<int> &coins, int amount) {
//         // Boundary condition check:
//         if (amount == 0)
//             return 0;
//         if (coins.empty())
//             return -1;
//
//         // 排序硬币数组（升序）/ Sort coins array (ascending)
//         sort(coins.begin(), coins.end());
//
//         vector<int> dp(amount + 1, INT_MAX);
//
//         dp[0] = 0; // 初始化
//
//         for (int i = 1; i <= amount; i++) {
//             for (int coin:coins) {
//                 if (coin <= i && dp[i-coin]!=INT_MAX) dp[i] = min(dp[i], dp[i - coin] + 1);
//                 else if (coin > i) break;
//             }
//         }
//         return dp[amount] == INT_MAX ? -1 : dp[amount];
//     }
// };


// Faster：大气一点一次顶到头

// class Solution {
// public:
//     int coinChange(vector<int> &coins, int amount, int c_index, int count, int ans) {
//         // c_index 当前正在处理的硬币面额在 coins 数组中的下标
//         if (amount == 0)
//             return min(ans, count);
//         if (c_index == coins.size())
//             return ans; // 已经处理到(超出)最小的coin，回溯;
//         for (int k = amount / coins[c_index]; k >= 0 && k + count < ans; k--) {
//             // 拉满:比如53 [5,3,2] > 5*10, k = 53/5 = 10
//             // 再比如: 54 [5,3,2] > 5*10, k = 54/5 = 10
//             ans = coinChange(coins, amount - k * coins[c_index], c_index + 1, count + k, ans);
//         }
//         return ans;
//     }
//
//     int coinChange(vector<int> &coins, int amount) {
//         if (amount == 0)
//             return 0;
//         sort(coins.rbegin(), coins.rend()); // 贪心：大到小排序
//         int ans = INT_MAX;
//         ans = coinChange(coins, amount, 0, 0, ans);
//         return ans == INT_MAX ? -1 : ans;
//     }
// };

