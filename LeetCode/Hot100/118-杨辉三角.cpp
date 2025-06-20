//
// Created by alpha on 2025/6/20.
//


#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows <=0) return {};  // same as return std::vector<std::vector<int>>{}; 创建一个默认对象返回
        vector<vector<int>> solution;
        solution.reserve(numRows);  // Pre-allocate space for better performance

        // Generate each row
        for (int i=0; i<numRows; i++) {
            vector<int> row(i+1);

            // Set first and last elements to 1
            row[0] = 1;  // First element
            row[i] = 1;  // Last element

            // Calculate middle elements
            for (int j = 1; j < i;j++)
                row[j] =  solution[i-1][j-1] + solution[i-1][j];

            solution.push_back(row);
        }

        return solution;
    }
};