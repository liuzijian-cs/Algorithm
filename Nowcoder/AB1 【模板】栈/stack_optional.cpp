//
// Created by zijianLiu on 2025/4/14.
//

#include <iostream>
//#include <stdexcept>
#include <optional>
#include <array>
using namespace std;

class Stack {
private:
    std::array<int, 100000> stack{};
    int index = -1;

public:
    Stack() = default;

    void push(int x) {
        stack[++index] = x;
    }

    std::optional<int> pop() {
      if (index == -1) return std::nullopt;
      return stack[index--];
    }

    std::optional<int> top() {
      if (index == -1) return std::nullopt;
      return stack[index];
    }

};

int main() {
    int n;
    cin >> n;
    Stack stack;
    for (int i = 0; i < n; i++) {
        string operation;
        cin >> operation;
        if (operation == "push") {
            int number;
            cin >> number;
            stack.push(number);
        } else if (operation == "pop") {
            std::optional<int> result = stack.pop();
            if (result.has_value()) std::cout << *result << std::endl; else std::cout << "error" << std::endl;
        } else if (operation == "top") {
            std::optional<int> result = stack.top();
            if (result.has_value()) std::cout << *result << std::endl; else std::cout << "error" << std::endl;
        } else {
            std::cout << "error" << std::endl;
        }
    }
    return 0;
}
