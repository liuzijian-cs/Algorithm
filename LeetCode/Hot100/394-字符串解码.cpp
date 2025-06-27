//
// Created by alpha on 2025/6/27.
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string result;

        stack<int> num;
        stack<string> str;

        string current_str = "";
        int current_num = 0;

        for (const char c: s) {
            if (isdigit(c)) current_num = current_num * 10 + (c - '0'); // 多位数情况
            else if (c == '[') {
                // 暂存器
                num.push(current_num);
                str.push(current_str);
                // 刷新
                current_str = "";
                current_num = 0;
            } else if (c == ']') {
                // 读
                int curr_num = num.top();
                num.pop();
                string curr_str = str.top();
                str.pop();
                for (int i = 0; i < curr_num; i++) curr_str += current_str;
                current_str = curr_str;
            } else current_str += c; // 推进
        }
        return current_str;
    }
};
