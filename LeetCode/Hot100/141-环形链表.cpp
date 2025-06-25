//
// Created by alpha on 2025/6/25.
//

// 思路：快慢指针

#include <iostream>


using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    // 构造函数 / Constructor
    ListNode(int x) : val(x), next(nullptr) {}
};

// 41.64% - 82.84%
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while (slow!=nullptr) {
            fast = fast->next;
            if (fast == slow) return true;
            if (fast == nullptr) return false;
            fast = fast->next;
            if (fast == slow) return true;
            if (fast == nullptr) return false;
            slow = slow->next;
        }
        return false;
    }
};