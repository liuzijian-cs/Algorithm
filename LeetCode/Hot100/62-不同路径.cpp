//
// Created by alpha on 2025/6/28.
//

// 动态规划：用一个二维数组 dp[m][n] 存储走到每个点的方法数。
// dp[i][j] 表示从 (0,0) 走到 (i,j) 的路径数。
// 其他格子只能从上方或者左方走过来，其路径数是左边和上边之和。
// 状态转移方程：dp[i][j] = dp[i-1][j] + dp[i][j-1]


#include <iostream>
#include <vector>
using namespace std;

// 优化到1D
// 100% - 79.09%
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m <= 0 || n <= 0) return 0;
        // 只有1行或1列：
        if (m == 1 || n == 1) return 1;
        // 1D dp：
        vector<int> dp(n, 1);
        // 填充DP：
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                dp[j] += dp[j-1];
        return dp[n - 1];
    }
};

// 100% - 38.89%
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m <= 0 || n <= 0) return 0;

        // 只有1行或1列：
        if (m == 1 || n == 1) return 1;

        // 2D dp：
        // dp[i][j]表示从(0,0)到(i,j)的路径数 / dp[i][j] represents the number of paths from (0,0) to (i,j)
        vector<vector<int>> dp(m, vector<int>(n, 1));

        // 填充DP：
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) { dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; }
        }

        return dp[m - 1][n - 1];
    }
};
