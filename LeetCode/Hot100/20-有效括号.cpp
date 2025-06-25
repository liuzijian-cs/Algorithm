//
// Created by alpha on 2025/6/25.
//
#include<iostream>
#include<unordered_map>
#include<vector>
#include<stack>
using namespace std;

// 100% - 31.34%
class Solution {
public:
    bool isValid(string s) {

        if(s.size()==0) return true;

        stack<char> stack;
        unordered_map<char, char> hashmap{
                {')', '('},
                {']', '['},
                {'}', '{'}
        };

        for (const char c : s) {
            if (c == '(' || c == '[' || c == '{') stack.push(c);
            if (c == ')' || c == ']' || c == '}') {
                if (stack.empty()) return false;
                if (stack.top() != hashmap[c]) return false;
                stack.pop();
            }
        }
        return stack.empty();
    }
};