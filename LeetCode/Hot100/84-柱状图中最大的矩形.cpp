#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// 分析：
//  具体来说，对于位置 i 的柱子（高度为 heights[i]），我们需要：
//  向左找到第一个高度小于 heights[i] 的位置
//  向右找到第一个高度小于 heights[i] 的位置
//  计算这个矩形的面积：heights[i] × (右边界 - 左边界 - 1)

// 最优方案：单调栈
// 维护一个单调递增的栈（存储柱子的索引）
// 当遇到更矮的柱子时，说明栈顶的柱子找到了右边界
// 通过栈中前一个元素确定左边界

// 87.10% -71.25%
class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        // 边界条件
        if (heights.empty()) return 0;

        // 初始化
        stack<int> stack;
        int result = 0;

        // Traverse all bars
        for (int i = 0; i < heights.size(); i++) {
            // Current bar is shorter than stack top
            // need to process stack top
            // 当遇到更矮的柱子时，说明栈顶的柱子找到了右边界
            while(!stack.empty() && heights[i] < heights[stack.top()]){
                int height = heights[stack.top()];
                stack.pop();
                // 左边界
                int width = stack.empty() ? i : (i - 1 - stack.top());
                int res = width * height;
                result = result > res ? result : res;
            }
            stack.push(i);
        }

        // 右边界
        while(!stack.empty()){
            int height = heights[stack.top()];
            stack.pop();

            int width = stack.empty() ? heights.size() : heights.size() - 1 - stack.top();

            int res = height * width;
            result = result > res ? result : res;

        }
        return result;
    }
};
 