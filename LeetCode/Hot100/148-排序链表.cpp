//
// Created by alpha on 2025/7/3.
//

// 排序的话，由于是单项链表，快排好像不行，二分？
// 你的思路评估：
// 快排确实不太适合单链表，因为需要随机访问和双向遍历
// 二分的思路是对的！归并排序是链表排序的最佳选择

// 对于链表排序，归并排序是最佳选择，因为：
//
// 时间复杂度：O(n log n)
// 空间复杂度：O(log n)（递归栈空间）
// 稳定排序
// 适合链表的线性访问特性

// 核心思路：
//
// 使用快慢指针找到链表中点
// 递归地对左右两部分进行排序
// 合并两个有序链表

#include <algorithm>
#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 归并排序：71.86% - 82.10%
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return head; // 递归出口

        ListNode *mid = findMid(head);

        ListNode *right_head = mid->next;
        mid->next = nullptr;

        ListNode *left = sortList(head);
        ListNode *right = sortList(right_head);

        return merge(left, right);

    }

private:
    ListNode *findMid(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *mid = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            mid = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        return mid;
    }

    ListNode *merge(ListNode *left, ListNode *right) {
        ListNode dummy;
        ListNode *curr = &dummy;
        while (left!=nullptr && right!=nullptr) {
            if (left->val <= right->val) {
                curr->next = left;
                left = left->next;
            }else {
                curr->next = right;
                right = right->next;
            }
            curr = curr->next;
        }
        curr->next = left==nullptr ? right : left;

        return dummy.next;
    }
};

// 4 - 2 - 1 - 3
//     prev
//         l       f
