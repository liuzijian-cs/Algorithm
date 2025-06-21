//
// Created by alpha on 2025/6/21.
//

#include <iostream>
#include <vector>

using namespace std;

// Dynamic Programming

// 我们用 dp[i] 表示：组成数字 i 需要的最少完全平方数个数。

// dp[1] = 1 （1 = 1²）
// dp[4] = 1 （4 = 2²）
// dp[12] = 3 (12 = 4 + 4 + 4)

// 初始状态
// dp[0] = 0 // 零不需要完全平方数。

// 状态转移方程
// 对于所有1到i的完全平方数j^2：
// dp[i] = min(dp[i], dp[i-j^2]+)
// 意思是，我尝试用一个“完全平方数j²”，把它减掉，剩下的部分( i-j² )再查最优解，然后加1
// 解释性例子：
// 假设 n = 12，我们想知道 dp[12] 吗？
// 试一下减去1²，剩11。dp[12] = min(dp[12], dp[11] + 1)
// 试一下减去2²=4，剩8。dp[12] = min(dp[12], dp[8] + 1)
// 试一下减去3²=9，剩3。dp[12] = min(dp[12], dp[3] + 1)
// 最终dp[12]=3（即4+4+4）

class Solution {
public:
    int numSquares(int n) {
        // Boundary condition check:
        if (n == 1)
            return 1;
        if (n <= 0)
            return 0;

        // Initialize DP array, dp[i] represents the minium number of perfect squares that sum to i
        vector<int> dp(n + 1, INT_MAX);

        // Base case: 0 requires 0 prefect squares
        dp[0] = 0;

        // Dynamic programming table filling process
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }

        return dp[n];
    }
};
