//
// Created by alpha on 2025/6/25.
//

// DFS函数需要传递当前索引参数
// 需要在每个递归层级记录当前路径
// 不一定需要排序（因为题目说可以任意顺序返回）

// 回溯法 (Backtracking) - 时间复杂度O(2^n × n)，空间复杂度O(n)
// 位运算法 (Bit Manipulation) - 时间复杂度O(2^n × n)，空间复杂度O(1)

#include <iostream>
#include <vector>
using namespace std;

//100%-25.03%
class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        if (nums.empty()) return {{}};
        vector<vector<int>> result;
        dfs(nums, 0, result);
        return result;
    }

private:
    vector<int> path;

    void dfs(const vector<int> nums, int index, vector<vector<int>> &result) {
        // 只能使用比当前大的数
        result.push_back(path);
        for (int i = index; i < nums.size(); i++) {
            path.push_back(nums[i]);
            dfs(nums, i+1, result);
            path.pop_back();
        }
    }
};

// 1 2 3
// -
// [],1,12,123,2,23,3