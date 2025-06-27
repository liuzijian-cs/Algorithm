//
// Created by alpha on 2025/6/27.
//

struct ListNode {
    int val;
    ListNode *next;

    // 构造函数 / Constructor
    ListNode(int x) : val(x), next(nullptr) {}
};

// 100% - 5.64%
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *prev = dummy;

        while (prev->next != nullptr && prev->next->next != nullptr) {
            ListNode * curr = prev->next;
            ListNode * next = curr->next;

            prev->next = next;
            curr->next = next->next;
            next->next = curr;

            prev = curr;
        }

        return dummy->next;
    }
};
