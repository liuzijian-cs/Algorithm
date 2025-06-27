//
// Created by alpha on 2025/6/27.
//

#include <iostream>
#include <vector>
using namespace std;

// 100% - 75.59%
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n <= 0) return vector<string>();

        vector<string> result;
        // string current_path;

        dfs(n, result);
        return result;
    }

private:
    int left = 0;
    int right = 0;
    string path;

    void dfs(int n, vector<string> &result) {
        if (left == n && right == n) {
            result.push_back(path);
            return;
        }
        if (right > left) return;

        if (left < n) { // 注意左边界
            left++;
            path.push_back('(');
            dfs(n, result);
            path.pop_back();
            left--;
        }

        if (right < left) {
            right++;
            path.push_back(')');
            dfs(n, result);
            path.pop_back();
            right--;
        }
    }
};
