//
// Created by alpha on 2025/8/4.
//

// 思路：啥也不会

// 解析：转置+翻转法 (Transpose + Reverse) ：
// 先将矩阵转置（行列互换）
// 再将每行进行水平翻转

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 100% - 66.09%
class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        // 边界条件
        if (matrix.empty() || matrix[0].empty()) return;

        // Step 1: Transpose
        int n = matrix.size();

        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) swap(matrix[i][j], matrix[j][i]);

        // Step 2: Reverse each row horizontally
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n / 2; j++) swap(matrix[i][j], matrix[i][n - j - 1]);
    }
};

int main() {
    cout << "Hello World" << endl;
    return 0;
}
