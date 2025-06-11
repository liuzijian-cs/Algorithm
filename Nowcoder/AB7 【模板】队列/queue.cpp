//
// Created by zijianLiu on 2025/4/21.
//

#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node *next = nullptr;

    Node(int data) { this->data = data; }

    int get_data() { return this->data; }
};

class queue {
private:
    Node *pfront = nullptr; // Front pointer (head)
    Node *prear = nullptr;  // Rear pointer (tail)
public:
    void push(int data) {
        Node *new_node = new Node(data);
        if (pfront == nullptr) {
            pfront = new_node;
            prear = new_node;
        } else {
            prear->next = new_node;
            prear = new_node;
        }
    }

    void pop() {
        if (pfront == nullptr) {
            cout << "error" << endl;
            return;
        } else {
            cout << pfront->get_data() << endl;
            if (pfront == prear) {
                free(pfront);
                pfront = prear = nullptr;
            } else {
                Node *temp = pfront;
                pfront = pfront->next;
                free(temp);
            }
        }
    }

    void front() {
        if (pfront == nullptr) {
            cout << "error" << endl;
            return;
        } else
            cout << pfront->get_data() << endl;
    }
};

int main() {
    int n;
    cin >> n;
    queue q;
    for (int i = 0; i < n; i++) {
        string opeartion;
        cin >> opeartion;
        if (opeartion == "push") {
            int data;
            cin >> data;
            q.push(data);
        } else if (opeartion == "pop")
            q.pop();
        else if (opeartion == "front")
            q.front();
        else
            cout << "error" << endl;


        if (opeartion == "push") {
        }
    }
}
