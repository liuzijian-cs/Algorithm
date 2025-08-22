/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */

// @lc code=start

// 思路：
// 1. 暴力搜索: O(m×n) 时间复杂度
// 2. 对每行进行二分查找: O(m×log n) 时间复杂度
// 3. 从右上角或左下角开始搜索: O(m+n) 时间复杂度 ⭐️ 最优解法

// 右上角元素是该行最大值，该列最小值
// 如果目标值小于当前值，向左移动（排除当前列）
// 如果目标值大于当前值，向下移动（排除当前行）
// 如果相等，找到目标值

// 37.19% - 35.66%
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        // 矩阵的行数rows和列数cols
        int size_row = matrix.size();
        int size_col = matrix[0].size();

        // 有效范围：
        int row = 0, col = size_col - 1;
        while (row < size_row && col >= 0) {
            int value = matrix[row][col];

            if (value == target) return true;
            else if (value > target) col--; // 向左移动
            else row++;                     // 向下移动
        }
        return false;
    }
};

// @lc code=end
