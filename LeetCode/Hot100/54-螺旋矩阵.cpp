//
// Created by alpha on 2025/7/3.
//
#include <iostream>
#include <vector>
using namespace std;

// 100% - 85.66%
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> result;

        if (matrix.empty() || matrix[0].empty()) return result;

        // Define four boundaries:
        int top = 0;
        int left = 0;
        int bottom = matrix.size() - 1;
        int right = matrix[0].size() - 1;

        while (top <= bottom && left <= right) {
            // Traverse top boundary form left to right
            for (int i = left; i <= right; i++) result.push_back(matrix[top][i]);
            top++;

            // Traverse right boundary from top to bottom
            for (int i=top;i<=bottom;i++) result.push_back(matrix[i][right]);
            right--;

            // Traverse bottom boundary from right to right
            if (top<=bottom) {
                for (int i =right;i>=left;i--) result.push_back(matrix[bottom][i]);
                bottom--;
            }

            // Traverse left boundary from bottom to top
            if (left<=right) {
                for (int i=bottom;i>=top;i--) result.push_back(matrix[i][left]);
                left++;
            }

        }
        return result;
    }
};

//
