//
// Created by alpha on 2025/7/3.
//
//
// Created by alpha on 2025/7/3.
//
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 这是一个典型的多源BFS（广度优先搜索）问题。我们需要：
// 从多个腐烂橘子（源点）同时开始扩散，求最短时间让所有新鲜橘子腐烂
// 每分钟所有腐烂橘子同时向四个方向扩散，这正是BFS的特点
// 边界条件：
// 如果一开始就没有新鲜橘子，返回0
// 如果有新鲜橘子但最终无法全部腐烂，返回 - 1

// 初始化：遍历网格，将所有腐烂橘子的位置加入队列，统计新鲜橘子数量
// BFS扩散：每轮处理当前队列中的所有腐烂橘子，向四个方向扩散
// 计时机制：每轮扩散算作一分钟
// 结果判断：如果还有新鲜橘子剩余，返回-1；否则返回总时间

// 100% - 86.04%
class Solution {
public:
    int orangesRotting(vector<vector<int>> &grid) {

        // 队列：用于记录烂橘子
        queue<pair<int, int>> queue;

        int good_oranges = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) good_oranges++;
                if (grid[i][j] == 2) queue.push({i, j});
            }
        }

        // 如果没有新鲜橘子，则直接返回0
        if (good_oranges == 0) return 0;

        // 四个方向的偏移量：上、下、左、右 / Four directions offset: up, down, left, right
        vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        int minutes = 0;

        while (!queue.empty() && good_oranges > 0) {
            size_t curr_bad_oranges = queue.size();

            for (int i = 0; i < curr_bad_oranges; i++) {
                // 取一个坏橘子
                auto [row, col] = queue.front();
                queue.pop();
                // 腐烂
                for (auto [dir_r, dir_c] : directions) {
                    int r = row + dir_r;
                    int c = col + dir_c;

                    // 边界判定
                    if (r>=0 && r<grid.size() && c>=0 && c<grid[0].size() && grid[r][c] == 1) {
                        grid[r][c] = 2;  // 腐烂
                        queue.emplace(r, c);  // 入队
                        good_oranges--;  // 好橘子--
                    }
                }
            }
            minutes++;
        }
        return good_oranges == 0? minutes : -1;
    }
};

int main() {
    Solution s;
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};  // 4
    cout<<s.orangesRotting(grid)<<endl;
    return 0;

}

