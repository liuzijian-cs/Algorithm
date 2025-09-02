#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// 思路：无；
// 分析：
// 这是一个简单的单调栈问题；
// 使用单调递减stack来存储数组下标
// 当遇到更高温度时，stack-top就是
// stack内使用保持温度递减的数组下标

// 32.27% - 72.41%
class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        int size = temperatures.size();
        vector<int> result(size, 0);
        stack<int> stack;

        for (int i = 0; i < size; i++) {
            // 当stack非空 && 温度大于stack top value
            // While stack is not empty and current temperature is greater than temperature at stack top index
            // 只要找到了温度更高的一天就立马出战
            while(!stack.empty() && temperatures[i] >temperatures[stack.top()]){
                int top = stack.top();
                stack.pop();
                result[top] = i - top;
            }
            stack.push(i);
        }
        return result;
    }
};
