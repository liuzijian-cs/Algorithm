//
// Created by alpha on 2025/7/2.
//

#include <iostream>
#include <vector>
using namespace std;

// abcde
// ace
//   a b c d e a
//   0 0 0 0 0 0
// a 1 1 1 1 1 1
// c 1 1 2 2 2 2
// a 1 1 2 2 2 3

// 思路，动态规划问题
// 转移矩阵我在想是否有必要做2D

// 你的思路方向正确，这确实是一个经典的动态规划问题。让我来完善一下分析：
// 使用二维DP表来记录两个字符串在不同位置的最长公共子序列长度
// 状态定义 State Definition
// dp[i][j] 表示 text1[0...i-1] 和 text2[0...j-1] 的最长公共子序列长度
// 状态转移方程 State Transition
// if text1[i-1] == text2[j-1]:
//     dp[i][j] = dp[i-1][j-1] + 1
// else:
//     dp[i][j] = max(dp[i-1][j], dp[i][j-1])

// 92.98% - 95.26%
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if (text1.empty() || text2.empty()) return 0;
        vector<int> dp0(text2.size() + 1, 0);
        vector<int> dp1(text2.size() + 1, 0);

        for (int i = 1; i <= text1.size(); ++i) {
            for (int j = 1; j <= text2.size(); ++j) {
                if (text1[i - 1] == text2[j - 1]) dp1[j] = dp0[j - 1] + 1;
                else dp1[j] = max(dp0[j], dp1[j - 1]);
            }
            dp0 = dp1;
        }
        return dp0[text2.size()];
    }
};

//
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        if (text1.empty() || text2.empty()) return 0;

        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));

        for (int i = 1; i <= text1.size(); i++) {
            for (int j = 1; j <= text2.size(); j++) {
                if (text1[i - 1] == text2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[text1.size()][text2.size()];
    }
};
