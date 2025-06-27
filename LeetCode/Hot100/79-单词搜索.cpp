//
// Created by alpha on 2025/6/27.
//
#include <iostream>
#include <vector>
using namespace std;

// 思路：
// 首先找到首字母，然后开始顺序的沿着上、右、下、左执行dfs，递归出口为完全相同 或 四个方向都不对
// 已经使用过的字母不能再使用，因此我们采用一个临时变量保存访问过的字母，并将访问过的字母用一个其他字符代替，这样就不需要额外的空间；
// 如果循环结束仍然没有匹配，则返回false


// 你的思路非常正确！这是解决单词搜索问题的经典方法。让我来帮你分析一下：
// ✅ 从首字母开始DFS搜索是正确的
// ✅ 四个方向（上、 右、 下、 左）的搜索策略正确
// ✅ 使用字符替换来标记访问过的位置，避免额外空间，这是很好的优化
// ✅ 递归出口的设计思路正确

// 是否最优：
// 你的思路已经是最优的！时间复杂度为O(M× N× 4 ^ L)，其中M是行数，N是列数，L是单词长度。 这是该问题的最优解法。

// 86.46% - 92.69%
class Solution {
public:
    bool exist(vector<vector<char>> &board, string word) {
        if (word.empty() || board.empty() || board[0].empty()) return false;

        int rows = board.size();
        int cols = board[0].size();

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (board[i][j] == word[0] && dfs(board, word, i, j)) return true;

        return false;
    }

private:
    int index = 0;

    bool dfs(vector<vector<char>> &board,const string& word, int row, int col) {
        if (index == word.size()) return true;
        // 注意：这里对列的上界检查写成了 col >= board.size()，正确的应该是 col >=
        // board[0].size()，否则操作非方阵时会越界。
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[index])
            return false;

        char temp = board[row][col];
        board[row][col] = '*';
        index++;

        // 递归结果未正确返回
        if (dfs(board, word, row, col + 1) || dfs(board, word, row, col - 1) || dfs(board, word, row + 1, col) ||
            dfs(board, word, row - 1, col))
            return true;

        board[row][col] = temp;
        index--;

        return false;
    }
};
