//
// Created by zijianLiu on 2025/4/14.
//

#include <iostream>
#include <stdexcept>
//#include <optional>
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

    int pop() {
        if (index == -1) throw std::out_of_range("error");
        return stack[index--];
    }

    int top() {
        if (index == -1) throw std::out_of_range("error");
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
            try {
                std::cout << stack.pop() << std::endl;
            } catch (const std::out_of_range &e) {
                std::cout << "error" << std::endl;
            }
        } else if (operation == "top") {
            try {
                std::cout << stack.top() << std::endl;
            } catch (const std::out_of_range &e) {
                std::cout << "error" << std::endl;
            }
        } else {
            std::cout << "error" << std::endl;
        }
    }
    return 0;
}
