//
// Created by alpha on 2025/6/25.
//

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// 思路：我想这个可以用小根堆实现？
// 你提到的小根堆思路需要仔细考虑。虽然小根堆可以快速获取最小值，但栈的pop操作需要删除栈顶元素，而堆中删除任意元素的复杂度是O(n)，这样就无法满足常数时间的要求。

// 最优解法是使用辅助栈（Auxiliary Stack）：
// 主栈存储所有元素
// 辅助栈存储每个位置对应的最小值
// 两个栈同步进行push和pop操作

// 69.55%-18.16%
class MinStack {
public:
    MinStack() {

    }

    void push(int val) {
        main.push(val);
        if (min.empty() || val< min.top()) {
            min.push(val);
        }else {
            min.push(min.top());
        }
    }

    void pop() {
        min.pop();
        main.pop();
    }

    int top() {
        return main.top();

    }

    int getMin() {
        return min.top();

    }
private:
    stack<int> main;
    stack<int> min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */