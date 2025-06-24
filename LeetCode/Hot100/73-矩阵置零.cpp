//
// Created by alpha on 2025/6/24.
//

// 给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。

// 思路：这个题目要求原地算法，是不是就是说完全不允许分配任何额外的存储空间？

// 那么我是否可以理解为这个题目是时间换空间，我的思路是首先第一遍遍历整个矩阵，把所有0变为-1，
// 然后二次遍历这个数组，只看-1的位置把-1的上下左右和其本身变为0

// 你的思路有一个关键问题：
// 标记冲突：将0改为-1作为标记，但如果原矩阵中本身就有-1，就会产生混淆
// 逻辑错误：题目要求的是将0所在的整行整列都置为0，而不是仅仅上下左右四个方向

// 原地算法并不意味着完全不能使用额外空间，而是要求空间复杂度为O(1)，即使用常数级别的额外空间。
// 最优解法是使用矩阵的第一行和第一列作为标记数组：

// 具体步骤如下：
// 1. 第一步：检查第一行和第一列是否有“0”
// 这是因为，第一行、第一列要用作“标记区”，但如果它们本身有0，后续全部置零时不能漏掉。
// 所以要先单独判断firstRowZero、firstColZero两个变量。

// 第二步：用第一行和第一列作“标记”
// 除了第一行、第一列，遍历其余元素。
// 如果matrix[i][j]是0，把matrix[i][0]和matrix[0][j]都置成0。
// 这样就记下了：第i行要零化、第j列要零化。

// 第三步：除了第一行第一列，其他位置看标记设0
// 再遍历其余位置，如果matrix[i][0]或matrix[0][j]为0，把matrix[i][j]也设为0。

// 第四步：根据第一步的结果处理第一行与第一列
// 如果firstRowZero为true，把整第一行都置零；
// 如果firstColZero为true，把整第一列都置零。

#include <iostream>
#include <vector>
using namespace std;

// 100% - 87.74%
class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) return;

        int rows = matrix.size();
        int cols = matrix[0].size();

        // Step1: Mark whether the first row and first column need to be set to zero:
        bool first_row_zero = false;
        bool first_col_zero = false;

        for (int i = 0; i < rows; i++)
            if (matrix[i][0] == 0) {
                first_col_zero = true;
                break;
            }

        for (int i = 0; i < cols; i++)
            if (matrix[0][i] == 0) {
                first_row_zero = true;
                break;
            }

        // Step2: Traverse the matrix (except first row and column),
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }


        // Step3: Set rows and columns to zero based on markers in first row and column
        for (int i = 1; i < rows; i++)
            for (int j = 1; j < cols; j++)
                if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;

        // Step4:
        if (first_row_zero)
            for (int i = 0; i < cols; i++)
                matrix[0][i] = 0;
        if (first_col_zero)
            for (int i = 0; i < rows; i++)
                matrix[i][0] = 0;
    }
};
