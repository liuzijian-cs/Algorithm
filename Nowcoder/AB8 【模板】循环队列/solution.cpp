//
// Created by alpha on 2025/4/22.
//

// [[deprecated]] 标记某个函数或变量已废弃，建议不要使用。
// [[nodiscard]] 标记返回值不可忽略。
// [[maybe_unused]] 标记变量可能未使用，避免编译器警告。

class Node {
public:
    explicit Node(const int data) : data(data), next(nullptr) {}

    [[nodiscard]] int get_data() const { return data; }

    [[nodiscard]] Node *get_next() const { return next; }

    Node &set_next(Node *new_next) {
        next = new_next;
        return *this;
    }

private:
    int data;
    Node *next;
};

class CircularQueue {
public:
    explicit CircularQueue(const int max_size): tail(nullptr), max_size(max_size) {}



    void push(const int data) {
        // push x: Insert integer x at the tail of the circular queue.
        // If the circular queue is full, output "full" (without quotes).
        // Otherwise, do not output anything.

        if (tail)



    }

    int front() {
        // front: Output the element at the front of the queue without dequeuing it.
        // If the queue is empty, output "empty" (without quotes).


    }

    int pop() {

    }

    // ~CircularQueue() {clear()}

    // void _clear() {
    //     if (tail == nullptr) return;
    // }



private:
    CircularQueue* tail = nullptr;  // Points to the tail node.
    int max_size;
    int size =0;
};



int main() {


    return 0;
}
