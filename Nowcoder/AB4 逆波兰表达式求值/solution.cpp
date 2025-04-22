//
// Created by alpha on 2025/4/15.
//

#include <cassert>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * @param tokens string字符串vector
     * @return int整型
     */
    int evalRPN(vector<string> &tokens) {
        // write code here

        stack<int> stack;
        int a, b;

        // Iterate through each token in the expression.
        for (const string &token: tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                a = stack.top();
                stack.pop();
                b = stack.top();
                stack.pop();
                if (token == "+")
                    stack.push(a + b);
                if (token == "-")
                    stack.push(b - a);
                if (token == "*")
                    stack.push(a * b);
                if (token == "/")
                    stack.push(b / a);
            } else
                stack.push(stoi(token));
        }
        return stack.top();
    }
};

int main() {
    Solution sol; // 创建 Solution 对象 (Create a Solution object)
    // 测试用例 1 (Test Case 1)
    std::vector<std::string> tokens1 = {"2", "1", "+", "4", "*"};
    assert(sol.evalRPN(tokens1) == 12); // 断言结果应为 12 (Assert the result should be 12)
    cout << "Case 1: Successful!" << endl;
    // 测试用例 2 (Test Case 2)
    std::vector<std::string> tokens2 = {"2", "0", "+"};
    assert(sol.evalRPN(tokens2) == 2); // 断言结果应为 2 (Assert the result should be 2)
    cout << "Case 1: Successful!" << endl;

    return 0;
}
