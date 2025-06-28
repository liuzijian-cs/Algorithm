//
// Created by alpha on 2025/6/28.
//

#include <iostream>
#include <vector>
using namespace std;

// 优化100% - 19.41%
class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
        dp[0][0] = grid[0][0];

        // 先填写第一行和第一列：
        for (int i = 1; i < grid.size(); i++) dp[i][0] = dp[i - 1][0] + grid[i][0];
        for (int j = 1; j < grid[0].size(); j++) dp[0][j] += dp[0][j - 1] + grid[0][j];

        // if (grid.size() == 1 || grid[0].size() == 1) return dp[grid.size() - 1][grid[0].size() - 1];

        for (int i = 1; i < grid.size(); i++) {
            for (int j = 1; j < grid[0].size(); j++) {
                dp[i][j] = grid[i][j] + min(dp[i - 1][j] , dp[i][j - 1] );
            }
        }
        return dp[grid.size() - 1][grid[0].size() - 1];
    }
};


// self: 29.97% - 50.08%
class Solution_self {
public:
    int minPathSum(vector<vector<int>> &grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
        dp[0][0] = grid[0][0];

        // 先填写第一行和第一列：
        for (int i = 1; i < grid.size(); i++) dp[i][0] = dp[i - 1][0] + grid[i][0];
        for (int j = 1; j < grid[0].size(); j++) dp[0][j] += dp[0][j - 1] + grid[0][j];

        if (grid.size() == 1 || grid[0].size() == 1) return dp[grid.size() - 1][grid[0].size() - 1];

        for (int i = 1; i < grid.size(); i++) {
            for (int j = 1; j < grid[0].size(); j++) {
                dp[i][j] = min(dp[i - 1][j] + grid[i][j], dp[i][j - 1] + grid[i][j]);
            }
        }
        return dp[grid.size() - 1][grid[0].size() - 1];
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};

    // solution.minPathSum(grid);

    cout<< solution.minPathSum(grid);

    return 0;
}
