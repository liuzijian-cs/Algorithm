//
// Created by zijianLiu on 2025/4/15.
//



# include <iostream>
# include <unordered_map>
# include <stack>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * @brief Checks if the given string is a valid parenthesis sequence.
     * @param s The input parenthesis string.
     * @return bool Boolean value, true for vaild, false for invalid.
     */

    static bool isValid(string s) {
        // write code here

        // Basic validation:
        if (s.empty()) return true;  // An empty string is consider valid.
        if (s.size() % 2 != 0) return false;  // A string with an odd length cannot be valid.

        // Variables:
        stack<char> stack;  // Create a stack of characters to store encountered opening brackets.
        // Create a hash map to store the matching relationship of brakets.
        unordered_map<char,char> bracket_map = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        // Iterate through each character of the input string.
        // Traverse the entire string character by character.
        // Iterate through the string.
        // Loop through the characters.
        // Process each character.
        // Go through each character in the string.

        for(char c:s){
            if (c == '(' || c == '{' || c == '[') stack.push(c);
            else if (c == ')' || c == '}' || c == ']') {
                if (stack.empty() || stack.top()!=bracket_map[c]) return false;
                stack.pop();
            }else return false;
        }
        return stack.empty();
    }
};

// 主函数，用于测试 (Main function for testing purposes)
int main() {
    // 创建解决方案对象 (Create a Solution object)
    Solution sol;
    // 测试用例 (Test cases)
    std::string s1 = "[]";
    std::string s2 = "()[]{}";
    std::string s3 = "(]";
    std::string s4 = "([)]";
    std::string s5 = "{[]}";
    std::string s6 = "[";
    std::string s7 = "]";
    std::string s8 = ""; // 空字符串测试 (Empty string test)
    std::string s9 = "((([])))";
    std::string s10 = "())"; // 右括号先出现 (Closing bracket appears first relevantly)
    // 输出测试结果 (Print test results)
    std::cout << "\"" << s1 << "\": " << (sol.isValid(s1) ? "true" : "false") << std::endl; // Expected: true
    std::cout << "\"" << s2 << "\": " << (sol.isValid(s2) ? "true" : "false") << std::endl; // Expected: true
    std::cout << "\"" << s3 << "\": " << (sol.isValid(s3) ? "true" : "false") << std::endl; // Expected: false
    std::cout << "\"" << s4 << "\": " << (sol.isValid(s4) ? "true" : "false") << std::endl; // Expected: false
    std::cout << "\"" << s5 << "\": " << (sol.isValid(s5) ? "true" : "false") << std::endl; // Expected: true
    std::cout << "\"" << s6 << "\": " << (sol.isValid(s6) ? "true" : "false") << std::endl; // Expected: false
    std::cout << "\"" << s7 << "\": " << (sol.isValid(s7) ? "true" : "false") << std::endl; // Expected: false
    std::cout << "\"" << s8 << "\": " << (sol.isValid(s8) ? "true" : "false") << std::endl; // Expected: true
    std::cout << "\"" << s9 << "\": " << (sol.isValid(s9) ? "true" : "false") << std::endl; // Expected: true
    std::cout << "\"" << s10 << "\": " << (sol.isValid(s10) ? "true" : "false") << std::endl; // Expected: false
    return 0; // 程序正常退出 (Program exits normally)
}