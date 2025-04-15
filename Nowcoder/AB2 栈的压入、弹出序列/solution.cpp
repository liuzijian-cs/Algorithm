//
// Created by zijianLiu on 2025/4/15.
//

#include <cassert>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param pushV int整型vector
     * @param popV int整型vector
     * @return bool布尔型
     */
    bool IsPopOrder(vector<int> &pushV, vector<int> &popV) {
        // write code here

        // Basic validation:
        // if the two sequences have different lengths, handel directly.
        if (pushV.size() != popV.size())
            return false;
        // if the two sequences or both empty, return true.
        if (pushV.empty() & popV.empty())
            return true;

        // Loop check:
        stack<int> stack;
        int checkpoint = 0;

        // traverse the push sequence:
        for (int pushValue: pushV) {
            // Push the current element into the stack.
            stack.push(pushValue);

            // Check if the top element of the stack is the current expected pop element.
            // As long as the stack is empty and the top element equals the expected pop element.
            while (!stack.empty() && stack.top() == popV[checkpoint]) {
                stack.pop(); // Pop the top element.
                checkpoint++; // Move to the next expected pop element.
            }
        }

        // If the stack is empty after all push operations, it means all elements were successfully popped in the
        // order of pop sequence.
        return stack.empty();
    }
};

int main() {
    Solution solution;

    // test case:
    vector<int> pushV1 = {1, 2, 3, 4, 5};
    vector<int> popV1_true = {4, 5, 3, 2, 1};
    vector<int> popV2_false = {4, 3, 5, 1, 2};

    cout << "Test Case1" << endl;
    assert(solution.IsPopOrder(pushV1, popV1_true) == true);

    cout << "Test Case2" << endl;
    assert(solution.IsPopOrder(pushV1, popV2_false) == false);

    cout << "Test Case3" << endl;
    vector<int> pushV3_empty = {};
    vector<int> popV3_true = {};
    assert(solution.IsPopOrder(pushV3_empty, popV3_true) == true);
}
