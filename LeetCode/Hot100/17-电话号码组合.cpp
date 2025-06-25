//
// Created by alpha on 2025/6/25.
//

// 思路：dfs回溯问题
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// 100% - 69.67%
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) return result;
        dfs(digits,0,result);
        return result;
    }

private:
    unordered_map<char, string> mapper{
            {'2', "abc"},    // 数字2对应abc / Digit 2 maps to abc
            {'3', "def"},    // 数字3对应def / Digit 3 maps to def
            {'4', "ghi"},    // 数字4对应ghi / Digit 4 maps to ghi
            {'5', "jkl"},    // 数字5对应jkl / Digit 5 maps to jkl
            {'6', "mno"},    // 数字6对应mno / Digit 6 maps to mno
            {'7', "pqrs"},   // 数字7对应pqrs / Digit 7 maps to pqrs
            {'8', "tuv"},    // 数字8对应tuv / Digit 8 maps to tuv
            {'9', "wxyz"}    // 数字9对应wxyz / Digit 9 maps to wxyz
    };
    string path;

    void dfs(string digits, int index, vector<string> &result) {
        // 递归出口
        if (index == digits.size()) {
            result.push_back(path);
            return;
        }


        for (int i = 0; i < mapper[digits[index]].size(); i++) {
            path.push_back(mapper[digits[index]][i]);
            dfs(digits, index + 1, result);
            path.pop_back();
        }
    }
};
