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

// // 87.10% -71.25%
// class Solution {
// public:
//     int largestRectangleArea(vector<int> &heights) {
//         // 边界条件
//         if (heights.empty()) return 0;

//         // 初始化
//         stack<int> stack;
//         int result = 0;

//         // Traverse all bars
//         for (int i = 0; i < heights.size(); i++) {
//             // Current bar is shorter than stack top
//             // need to process stack top
//             // 当遇到更矮的柱子时，说明栈顶的柱子找到了右边界
//             while(!stack.empty() && heights[i] < heights[stack.top()]){
//                 int height = heights[stack.top()];
//                 stack.pop();
//                 // 左边界
//                 int width = stack.empty() ? i : (i - 1 - stack.top());
//                 int res = width * height;
//                 result = result > res ? result : res;
//             }
//             stack.push(i);
//         }

//         // 右边界
//         while(!stack.empty()){
//             int height = heights[stack.top()];
//             stack.pop();

//             int width = stack.empty() ? heights.size() : heights.size() - 1 - stack.top();

//             int res = height * width;
//             result = result > res ? result : res;

//         }
//         return result;
//     }
// };


// 复习：250903
class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        // 思路：
        // 基于单调栈：stack top value > stack in value
        // left: 找到第一个比当前小的； 
        // right：找到第一个小的；
        
        // 边界情况：
        if(heights.empty()) return 0;

        // 初始化问题：
        stack<int> stack;

        int result = 0;

        // Traverse the entire array：
        for(int i=0; i<heights.size(); i++){
            // 如果栈非空 && 栈顶元素比当前元素大（右边界找到了）
            while(!stack.empty() && heights[stack.top()]>heights[i]){
                // 高度
                int top_value_index = stack.top();
                stack.pop();
                // 右侧边界为 i - 1
                // 左侧边界为stack.top()
                // 修正点：当栈清空时，说明左边没有更小的元素，
                // 理想的“虚拟左边界”应为 -1（而不是 0），否则会少算一列，产生 off-by-one 错误。
                int left_index = stack.empty() ? -1 : stack.top();

                // 宽度 = 右边界(i-1) - 左边界(left_index)
                int width = i - 1 - left_index; // 等价于 stack.empty()? i : i - stack.top() - 1

                int size = heights[top_value_index] * width;

                result  = result > size ? result : size;
            }
            stack.push(i);
        }

        // 处理栈非空情况：也就是栈严格有序，右边的始终比左边的大：
        while(!stack.empty()){
            // 栈顶元素出战：
            int top_value_index = stack.top();
            stack.pop();

            // 此时没有右侧边界：右侧“虚拟边界”为 n（下标 n-1 的右一位）
            // 修正点：当栈清空时，左边同理应取 -1 作为“虚拟左边界”
            int left_index = stack.empty() ? -1 : stack.top();

            // 宽度 = 右边界(n-1) - 左边界(left_index) = n - left_index - 1
            int width = static_cast<int>(heights.size()) - 1 - left_index; 

            int size = width * heights[top_value_index];

            result = result > size ? result : size;

        }
        return result;
    }
};

int main(){

    Solution s = Solution();
    vector<int> test_input = {9,0};
    // 打印结果以便快速验证
    int result = s.largestRectangleArea(test_input);
    cout << result << endl;




    return 0;
}
