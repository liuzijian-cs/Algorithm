//
// Created by alpha on 2025/4/17.
//

#include <iostream>
#include <stack>
using namespace std;


class Solution {
public:
    // Function: Remove adjacent duplicate letters.
    string Remove(const string& s) {
        // Traverse the input string from right to left.
            // use a stack to manage the characters.
                // If the top element of the stack is the same as the current
                // character, pop the stack (remove the character).
                // Otherwise, push the current character onto the stack.
            // After processing all characters, construct the final string buy popping
            // element from the stack.
        stack<char> stack;
        for(auto it = s.rbegin(); it != s.rend(); it++) {
            if(!stack.empty() && *it == stack.top()) stack.pop();
            else stack.push(*it);
        }

    }

};

int main() {
    // Traverse the input string from right to left.
    // use a stack to manage the characters.
    // If the top element of the stack is the same as the current
    // character, pop the stack (remove the character).
    // Otherwise, push the current character onto the stack.
    // After processing all characters, construct the final string buy popping
    // element from the stack.
    string s;
    while (cin >> s) {
        stack<char> stack;
        for (auto it = s.rbegin(); it != s.rend(); it++) {
            if (!stack.empty() && *it == stack.top())
                stack.pop();
            else
                stack.push(*it);
        }
        if (stack.empty()) {
            cout << "0" << endl;
            continue;
        }

        while (!stack.empty()) {
            cout << stack.top();
            stack.pop();
        }
        cout << endl;
    }
    return 0;
}
