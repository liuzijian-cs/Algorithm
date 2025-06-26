//
// Created by alpha on 2025/6/26.
//

// 思路：这个题考察的是组合

// 首先题目已经保证了输入数组是无重复元素的，但是似乎没有说按序排列，因此我想是否有必要进行数组的从小到大排列；
// 随后我们开始进行dfs进行深度遍历，从最小的数字开始，每一次计算need=target - 当前值看看还需要多少
// 如果need == 0 那么将内容放在数组里 index += 1（以保证禁止使用重复数字）；如果<0则直接退出
// 边界条件：如果为空返回空二维数组（应该没什么必要？）；

// 思路分析
// 你的整体思路是正确的，这确实是一个典型的回溯算法（backtracking） 问题。让我帮你完善一下：
// 你的思路中正确的部分：
// ✅ 使用DFS进行深度遍历
// ✅ 计算剩余需要的值 need = target - 当前值
// ✅ need == 0 时加入结果，need < 0时剪枝
// ❌ "index += 1（以保证禁止使用重复数字）" - 题目明确说可以无限制重复使用同一个数字
// 这个其实是在保证一个顺序性，
// ✅ 排序是一个很好的优化思路，可以帮助剪枝

// 核心思路：
// 使用回溯算法，每次选择一个数字加入当前组合
// 为避免重复组合（如[2, 3, 3] 和[3, 2, 3]），需要保证选择的顺序性
// 从当前索引开始选择，可以重复选择同一个数字，但不能回头选择之前的数字


#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 100% - 74.70%
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        // Stor all valid combinations:
        // vector<int> path;

        // Sort array for pruning optimization:
        sort(candidates.begin(), candidates.end());

        // Start depth-first search:
        backtrack(candidates, target, 0);

        return result;
    }

private:
    vector<int> path;
    vector<vector<int>> result;

    void backtrack(vector<int>& candidates, int target, int start_index) {
        // target 为当前的目标值

        // 递归出口
        if (target == 0) {
            result.push_back(path);
            return;
        }

        // Iterate through candidate numbers
        for (int i = start_index; i < candidates.size(); i++) {
            // Pruning: if current number > target, later numbers won't work either
            if (candidates[i] > target) break;
            path.push_back(candidates[i]);

            backtrack(candidates, target - candidates[i], i);

            // Undo choice (backtrack)
            path.pop_back();
        }
    }
};
