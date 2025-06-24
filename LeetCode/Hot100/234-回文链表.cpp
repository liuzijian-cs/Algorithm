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

// 思路
// 有些无脑，首先构建一个stack，用于存储每一个节点的地址，第一次遍历将所有元素的地址入栈，第二次遍历依次出栈，对比是否与当前指针元素相同
// 如果遍历完正好栈空，则true，反之直接false，是否有更高效的方法

// 逻辑上是正确的，但有一个小问题：你应该存储节点的值而不是地址，因为回文比较的是值的内容。
// 不过这个方法的时间复杂度是O(n)，空间复杂度也是O(n)，并不是最优解。

// Optimal Solution Analysis
// 最优的解法是快慢指针 + 反转链表的组合：
// 使用快慢指针找到链表的中点
// 反转后半部分链表
// 同时遍历前半部分和反转后的后半部分进行比较
// 恢复链表结构（可选）
// 时间复杂度：O(n)，空间复杂度：O(1)

// 77.66% - 74.78%
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;  // Empty or single node is palindrome

        // Step 1: Find middle using two pointers
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half
        ListNode* prev = nullptr;
        ListNode* curr = slow->next;

        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // Step 3: Compare first half with reversed second half
        ListNode* prev_list = head;
        ListNode* curr_list = prev;

        while (curr_list != nullptr) {
            if (prev_list->val != curr_list->val) return false;
            prev_list = prev_list->next;
            curr_list = curr_list->next;
        }
        return true;
    }
};