//
// Created by alpha on 2025/6/28.
//

#include <iostream>
#include <vector>
using namespace std;

// 动态规划思想：
// 用二维bool数组dp[i][j]表示字符串s下标从i到j的字串s[i...j]是否为回文
// dp[i][j] = true，表示 s[i..j] 为回文串
// dp[i][j] = false，表示 s[i..j] 不是回文串
// 状态转移：
// 当 s[i] == s[j] 时，
// 如果子串长度小于3（即 j - i < 2），s[i..j] 必然回文（长度为1或2且两端字母相等）。
// 如果子串长度大于2，s[i..j] 是否回文取决于内层子串 s[i+1..j-1] 是否回文：
// 则 dp[i][j] = dp[i+1][j-1]。
// 当 s[i] != s[j] 时，dp[i][j] = false

// 22.22% 40.46%
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) return s;

        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));

        int max_len = 1; // 当前最长回文长度 / current max palindrome length
        int start = 0;   // 最长回文的起始索引 / start index of longest palindrome

        // 初始化：所有长度为 1 的子串都是回文 / all substrings of length 1 are palindromes
        for (int i = 0; i < s.size(); i++) dp[i][i] = true; // 对角线


        // 枚举子串长度 len 从 2 到 n / consider all lengths from 2 to n
        for (int len = 2; len <= s.size(); len++) {
            // 对于每个起点 i，终点 j = i + len - 1
            for (int i = 0; i + len - 1 < s.size(); i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    if (len == 2) dp[i][j] = true;
                    else dp[i][j] = dp[i + 1][j - 1];
                } else dp[i][j] = false;

                // 如果 s[i..j] 是回文且比当前记录更长，则更新
                if (dp[i][j] && len > max_len) {
                    max_len = len;
                    start = i;
                }
            }
        }

        return s.substr(start, max_len);
    }
};
