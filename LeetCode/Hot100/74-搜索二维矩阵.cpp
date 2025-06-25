//
// Created by alpha on 2025/6/25.
//

// 这是一个查找问题，那么一定是采用二分查找，由于是查找具体的值，具有唯一性，因此这里二分采用lower_bound还是upper_bound并不重要
// 搜索顺序我想应该是先对列查找，锁定区间（这里应该是upper_bound），随后对行查找

// 最优解法（推荐）
// 核心思想：将二维矩阵映射为一维有序数组，利用数学转换 matrix[mid/n][mid%n] 进行一次二分查找
// 优势：代码简洁，时间复杂度 O(log(m× n))，空间复杂度 O(1)

// 100% - 75.76%
class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int rows = matrix.size();    // 一共有rows行（列编号）
        int cols = matrix[0].size(); // 每行有cols列

        int left = 0, right = rows * cols;

        while (left < right) {
            int mid = left + (right - left) / 2;
            int mid_value = matrix[mid / cols][mid % cols];

            if (target > mid_value) left = mid + 1;
            else if (target == mid_value) return true;
            else right = mid;
        }
        return false;
    }
};
