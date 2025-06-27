//
// Created by alpha on 2025/6/27.
//

struct ListNode {
    int val;
    ListNode *next;

    // 构造函数 / Constructor
    ListNode(int x) : val(x), next(nullptr) {}
};

// 思路： |-------------------|-------n------|
// 快慢指针？
// 快指针用于确定总长度，如果在左边则从头开始确定位置，入股在右边则调用慢指针；

// 你的思路分析：
// 你提到的快慢指针方向是对的，但实现细节还需要完善。你的思路中"快指针确定总长度，根据位置选择策略"这个想法会让问题复杂化。
// 这道题的最佳解法确实是双指针（快慢指针） 方法，但具体实现是：
// 让快指针先走 n+1 步
// 然后快慢指针同时移动
// 当快指针到达末尾时，慢指针正好指向待删除节点的前一个节点
// 执行删除操作

// 这样只需要一次遍历，时间复杂度O(L)，空间复杂度O(1)。

// 100% - 32.55%
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // 边界条件检查 / Boundary condition check
        if (!head || n <= 0) return head;

        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *fast = dummy;
        ListNode *slow = dummy;

        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        while (fast!=nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* node_del = slow->next;
        if (node_del!=nullptr) {
            slow->next=slow->next->next;
            delete node_del;
        }

        ListNode* result = dummy->next;
        delete dummy;

        return result;
    }
};

// 1.02% - 70.74 %
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == nullptr || n <= 0) return head;
        // if (head->next == nullptr && n == 1) return nullptr;

        ListNode *fast = head;
        ListNode *slow = head;

        // 1 2 3 4 5 null
        // s     f
        //     s     f
        // 1 2 3   5

        // Step: fast先走n步
        // for (int i = 0; i < n + 1 && fast != nullptr; i++, fast = fast->next) {}

        for (int i = 0; i < n + 1; i++) {
            if (fast == nullptr) {
                // 要删头节点
                ListNode *tmp = head;
                head = head->next;
                delete tmp;
                return head;
            }
            fast = fast->next;
        }


        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // delete
        ListNode *kill = slow->next;
        slow->next = kill->next;
        delete kill;

        return head;
    }
};
