//
// Created by alpha on 2025/6/22.
//

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

// 按照自己的思路重新完成：

class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        // Boundary condition check:
        if (s.empty()) return true;
        if (wordDict.empty()) return false;

        // Dynamic Programming:
        unordered_set<string> set(wordDict.begin(), wordDict.end());

        int maxlength = 0;
        // int maxlength = INT_MIN;
        // maxlength 应该初始化为 0，否则如果字典为空（虽然你前面已经判断过），maxlength 会是负数，后续 i - maxlength
        // 可能出错。
        for (const string &word: wordDict) maxlength = maxlength > word.length() ? maxlength : word.length();

        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;

        //  leetcode
        // 100000000
        //  j__i
        // 10001


        // Main Loop:
        for (int i = 1; i <= s.length(); i++) {
            for (int j = max(0, i - maxlength); j < i; j++) {
                if (dp[j] && set.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.length()];
    }
};

// 这是一个典型的动态规划问题。我们需要判断字符串 s 是否可以被字典中的单词完全拆分

// 思路：
// 使用动态规划，dp[i] 表示字符串 s 的前 i 个字符是否可以被字典中的单词拆分
// 对于每个位置 i，我们检查所有可能的分割点 j（其中 j < i）
// 如果 dp[j] 为 true 且 s[j:i] 在字典中存在，则 dp[i] = true

// 进一步理解：
// 我们想知道，字符串s的前i个字符s[0...i-1]能不能由字典wordDict中的单词组成。
// 为此，我们定义状态数组dp[i]：
// dp[i] == true 表示前i个字符能拆分
// dp[i] == false 表示前i个字符不能拆分
// 状态转移
// 对于s[0...i-1]这个子串，我们考虑它的最后一次分割点j，也就是说：
// 看看dp[j]是不是true
// 再看看s[j...i-1]是不是在wordDict中
// 换句话说，只要存在某个j满足：
// s.substr(j, i-j)在字典中
// 则dp[i] = true！
// 比如:
// s = "applepenapple"
//
//         wordDict = ["apple", "pen"]
//
//         初始化：dp[0] = true（空字符串一定可以拆分）
//
//                 开始DP过程：
//
//                         i = 1,
//         只看s[0] ："a"不在字典，dp[1] = false i = 2, 看s [0:2] ："ap"不在字典，dp[2] = false... i = 5,
//         看s [0:5] ："apple"在字典, 并且dp[0] = true，所以dp[5] = true i = 8, 看s [5:8] ："pen"在字典,
//         并且dp[5] = true，所以dp[8] = true i = 13, 看s [8:13] ："apple"在字典,
//         并且dp[8] = true，所以dp[13] = true 最终dp[13] = true，说明整个字符串可以拆分！
//
//
// class Solution {
// public:
//     bool wordBreak(string s, vector<string> &wordDict) {
//         // Boundary condition check:
//         if (s.empty()) return true;
//         if (wordDict.empty()) return false;
//
//         int n = s.length();
//
//         // Convert dictionary to hash set for faster lookup:
//         unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
//
//         // Get max word length for optimization:
//         int maxWordLen = 0;
//         for (const string &word: wordDict) maxWordLen = maxWordLen > word.size() ? maxWordLen : word.size();
//
//         // Dynamic Programming:
//         vector<bool> dp(s.length() + 1, false);
//
//         dp[0] = true;
//
//         // Main dynamic programming loop:
//         for (int i = 1; i <= s.length(); i++) {
//             // Iterate through all possible split points:
//             // Optimization: only check split points within max word length range:
//             for (int j = max(0, i - maxWordLen); j < i; j++) {
//                 if (dp[j] && wordSet.count(s.substr(j, i - j))) {
//                     dp[i] = true;
//                     break; // Break once we find a valid segmentation
//                 }
//             }
//         }
//
//         return dp[s.length()];
//     }
// };
