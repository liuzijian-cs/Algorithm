//
// Created by alpha on 2025/6/25.
//

// 思路：递归

// 你提到的递归思路是完全正确的！全排列问题的核心思想确实是使用深度优先搜索(DFS)的递归回溯方法。
// 使用回溯算法，每次选择一个未使用的数字加入当前排列
// 当排列长度等于原数组长度时，说明找到了一个完整的排列
// 回溯时需要撤销当前选择，尝试其他可能性

// 时间复杂度: O(n! × n) - 生成所有排列需要O(n!)，每个排列复制需要O(n)
//  空间复杂度: O(n) - 递归栈深度和used数组的空间

// 步骤 1：递归入口（Recursion Entry）
// 开始时：currentPath 为空 [], used = [false, false, false]
// 步骤 2：第1层循环（First Level）
// 依次尝试用1、2、3作为第一个数。
// 选1：currentPath = [1] used = [true, false, false] 递归填剩下的位置
// 选2：currentPath = [2] used = [false, true, false] 递归
// 选3：currentPath = [3] used = [false, false, true] 递归

// 步骤 3：第2层循环（Second Level）


#include <filesystem>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 全排列，复习1：20250625
// 100% - 84.64%
class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> result;
        if (nums.empty()) return result;
        if (nums.size() == 1) {
            result.push_back(nums);
            return result;
        }

        dfs(nums,result);
        return result;
    }

private:
    int mask = 0;
    vector<int> path;

    void dfs(vector<int> &nums, vector<vector<int>> &result) {
        // 递归出口
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (mask & (1<<i)) continue;
            mask |= (1 << i);
            path.push_back(nums[i]);

            dfs(nums, result);

            mask &= ~(1 << i);
            // 0001
            // 1110
            // 0000
            path.pop_back();
        }
    }
};

// dfs: 100% - 49.53%
class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        if (nums.empty()) return vector<vector<int>>();
        used.resize(nums.size(), false);465
        dfs(nums);
        return result;
    }

private:
    // C++ 的递归函数默认是在单线程（single thread）、单实例（single call stack）下运行的，
    // 也就是说每次dfs调用，实际上都是在当前对象的同一实例上进行的，每一级递归不会和其他递归“并行”或者“交叉”，依然是顺序展开和回溯。
    vector<vector<int>> result;
    vector<int> current_path;
    vector<bool> used;

    void dfs(const vector<int> &nums) {
        // 递归出口
        if (current_path.size() == nums.size()) {
            result.push_back(current_path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            current_path.push_back(nums[i]);
            used[i] = true;

            dfs(nums);

            // backtrack
            current_path.pop_back();
            used[i] = false;
        }
    }
};

// bfs 6.79% - 5.01%
class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> result;
        if (nums.empty()) return result;
        if (nums.size() == 1) {
            result.push_back(nums);
            return result;
        }

        queue<pair<vector<int>, int>> queue;

        // Initialize: add each number as starting state to queue
        for (int i = 0; i < nums.size(); i++) {
            vector<int> inti_path = {nums[i]};
            int used_mask = 1 << i; // 1 << i 就是把第i位变成1，其余位是0。
            queue.push({inti_path, used_mask});
        }

        // Main BFS loop
        while (!queue.empty()) {
            auto [curr_path, used_mask] = queue.front();
            queue.pop();

            // If current permutation length equals original array length, it's a complete permutation
            if (curr_path.size() == nums.size()) {
                result.push_back(curr_path);
                continue;
            }

            // Try adding each unused number
            for (int i = 0; i < nums.size(); i++) {
                if (used_mask & (1 << i)) continue;

                // Create new permutation and mask
                vector<int> new_path = curr_path;
                new_path.push_back(nums[i]);
                int new_mask = used_mask | (1 << i);

                queue.push({new_path, new_mask});
            }
        }
        return result;
    }
};
