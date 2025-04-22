//
// Created by alpha on 2025/4/17.
//
# include <vector>
#include <stdexcept>


# include <iostream>
# include <unordered_map>
# include <stack>
# include <cctype>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 返回表达式的值
     * @param s string字符串 待计算的表达式
     * @return int整型
     */
    int solve(string s) {
        // write code here

        // The operand stack and the operator/parenthesis stack
        stack<int> nums;
        stack<char> ops;

        for (int i = 0; i < s.size(); ++i) {
            if (isspace(s[i])) continue;  // Switch whitespace
            if (isdigit(s[i])) {  // Handle operand
                int this_num = 0;
                while(i <s.size() && isdigit(s[i])) this_num = this_num * 10 + (s[i++] - '0');
                nums.push(this_num);
                i--;
            }
            else if (precedence.count(s[i])) {  // Handle operator
                while(!ops.empty() && ops.top() != '(' && precedence.at(s[i]) <= precedence.at(ops.top()))
                    _calculate(nums,ops);
                ops.push(s[i]);
            }
            else if (s[i] == '(')  ops.push(s[i]);
            else if (s[i] == ')') {
                while(!ops.empty() && ops.top() != '(') _calculate(nums,ops);
                ops.pop();
            }
            else;
        }

        // Process remining operators:
        while(!ops.empty()) _calculate(nums,ops);

        return nums.top();
    }


private:
    const unordered_map<char, int> precedence = {
        {'+', 1},
        {'-', 1},
        {'*', 2},
    };

    static void _calculate(stack<int>& nums, stack<char>& ops){
        if(nums.size()<2 || ops.empty()) return;
        int op1 = nums.top(); nums.pop();
        int op2 = nums.top(); nums.pop();
        switch(ops.top()){
            case '+': nums.push(op2+op1); break;
            case '-': nums.push(op2-op1); break;
            case '*': nums.push(op2*op1); break;
            default: break;
        }
        ops.pop();
    }
};


int main() {
    std::string expression;
    // 示例测试用例
    // Example test cases
    std::vector<std::string> test_cases = {
        "(3+4)*(5+(2-3))"
        // "1+2",                  // 3
        // " 3 - 1 ",              // 2
        // "(1+2)-3",              // 0
        // "1-(2+3)",              // -4
        // "10 + 20 - 5",          // 25
        // "(1+(4+5+2)-3)+(6+8)",  // 1+11-3+14 = 23
        // "1",                    // 1
        // "(5)",                  // 5
        // "1 - ( -2 + 3 )"      // 需要处理负数或确保输入不含负号开头的数字，当前版本不直接支持一元负号，会当作减法
        //                         // Requires handling negative numbers or ensuring input doesn't start numbers with minus. Current version doesn't directly support unary minus; treats it as subtraction.
        //                         // Let's assume valid inputs only contain binary +,- and non-negative integers for now based on AB6 description.
        //                         // Example "1 - (-2+3)" would be treated as "1 - (0 - 2 + 3)" if unary minus was naively handled or likely fail.
        //                         // Given the problem description only mentions integers and binary +,-,*; we stick to that.
        //                         // Let's test a slightly more complex valid one:
        // "1 + (2 - (3 - 4)) + 5" // 1 + (2 - (-1)) + 5 = 1 + 3 + 5 = 9
    };
    // 运行测试用例
    // Run test cases

    Solution s;
    for (const auto& expr : test_cases) {
        try {
            long long result = s.solve(expr);
            // 输出表达式和结果
            // Output the expression and the result
            std::cout << "表达式 (Expression): \"" << expr << "\"" << std::endl;
            std::cout << "计算结果 (Result): " << result << std::endl << std::endl;
        } catch (const std::runtime_error& e) {
            // 捕获并打印运行时错误
            // Catch and print runtime errors
            std::cerr << "处理表达式 \"" << expr << "\" 时发生错误 (Error processing expression \"" << expr << "\"): " << e.what() << std::endl << std::endl;
            // English: std::cerr << "Error processing expression \"" << expr << "\": " << e.what() << std::endl << std::endl;
        }
    }
    // // 可以取消注释下面部分来接收用户输入
    // // Uncomment the following section to accept user input
    // std::cout << "请输入一个表达式 (Please enter an expression): ";
    // std::getline(std::cin, expression); // 使用 getline 读取可能包含空格的整行
    //                                     // Use getline to read the entire line which might contain spaces
    // try {
    //     long long result = evaluateExpression(expression);
    //     std::cout << "计算结果 (Result): " << result << std::endl;
    // } catch (const std::runtime_error& e) {
    //     std::cerr << "错误 (Error): " << e.what() << std::endl;
    //     return 1; // Indicate error
    // }
    return 0; // 程序成功结束 (Program finished successfully)
}