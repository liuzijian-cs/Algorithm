//
// Created by alpha on 2025/6/27.
//


struct ListNode {
    int val;
    ListNode *next;

    // 构造函数 / Constructor
    ListNode(int x) : val(x), next(nullptr) {}
};

// 24.48% - 76.41%
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;

        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {

            int sum = (l1 == nullptr ? 0 : l1->val) + (l2 == nullptr ? 0 : l2->val) + carry;
            carry  = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;

            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        cur = dummy->next;
        delete dummy;
        return cur;
    }
};
