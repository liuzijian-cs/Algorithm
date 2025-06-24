//
// Created by alpha on 2025/6/24.
//


#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    // 构造函数 / Constructor
    ListNode(int x) : val(x), next(nullptr) {}
};

//100%-61.07%
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* p = nullptr;
        ListNode* q = head;

        while (q!=nullptr) {
            ListNode* tmp = q->next;
            q->next = p;
            p = q;
            q = tmp;
        }
        return p;
    }
};
