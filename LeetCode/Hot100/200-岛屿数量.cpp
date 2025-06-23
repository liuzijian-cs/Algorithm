//
// Created by alpha on 2025/6/23.
//

// 我感觉有点像卷积边缘检测，但又肯定不是这个思路
//
// 思路
// 分配一个遍历图，如果遍历过则标记为T，否则为F
//
// 我想从[0][0]出发？然后广度/深度优先遍历，把这个岛屿所有的陆地标记为T,result+1，然后从下一个为F且为1的地点继续

// 你的思路完全正确：

// 1. 使用额外的访问标记数组来记录已访问的位置
// 2. 遍历整个网格，当遇到未访问的陆地('1')时，启动DFS / BFS
// 3. 在DFS / BFS过程中标记所有连通的陆地，岛屿数量 +1
// 4. 继续遍历直到处理完所有位置
// 时间复杂度O(m× n)，空间复杂度O(m× n)。
//
// 不过我建议一个小优化：可以直接在原数组上标记，将访问过的 '1'改为 '0'，这样可以节省额外的空间。

#include <iostream>
#include <vector>
using namespace std;

// 73.6% - 84.13%
class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        int result = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, rows, cols, i, j);
                    result++;
                }
            }
        }
        return result;
    }

private:
    void dfs(vector<vector<char>> &grid, int rows, int cols, int i, int j) {
        // 递归结束条件
        if (i < 0 || j < 0 || i >= rows || j >= cols || grid[i][j] == '0') return;

        // Mark current position as visited (island sinking method)
        grid[i][j] = '0';

        // dfs
        dfs(grid, rows, cols, i - 1, j);
        dfs(grid, rows, cols, i + 1, j);
        dfs(grid, rows, cols, i, j - 1);
        dfs(grid, rows, cols, i, j + 1);
    }
};
