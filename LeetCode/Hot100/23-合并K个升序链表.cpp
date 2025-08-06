//
// Created by alpha on 2025/8/4.
//

// 思路：有一点区间合并的思想，始终维护每一个列表的最小值
// 比如：1-[1,4,5],1-[1,3,4],1-[2,6]
// 持续选择最小值

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 分支
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty()) return nullptr;

        int n = lists.size();

        for (int step=1;step<n;step*=2)
            for (int i=0; i+step<n;i+=step*2)
                lists[i] = mergeTwoList(lists[i], lists[i+step]);
        return lists[0];

    }

private:
    ListNode *mergeTwoList(ListNode *l1, ListNode *l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        ListNode dummy(0);
        ListNode *curr = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        curr->next = l1 ? l1 : l2;
        return dummy.next;
    }
};

class Solution {
public:
    // 方法1：使用最小堆（优先队列）
    // Method 1: Using min heap (priority queue)
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // 边界条件检查：空列表或所有链表为空
        // Boundary condition check: empty list or all linked lists are null
        if (lists.empty()) return nullptr;

        // 自定义比较器：按节点值降序排列（实现最小堆）
        // Custom comparator: sort by node value in descending order (to implement min heap)
        auto compare = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };

        // 创建优先队列（最小堆）
        // Create priority queue (min heap)
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> pq(compare);

        // 将所有非空链表的头节点加入堆中
        // Add all non-null head nodes to the heap
        for (ListNode* list : lists) {
            if (list != nullptr) {
                pq.push(list);
            }
        }

        // 创建虚拟头节点和当前指针
        // Create dummy head node and current pointer
        ListNode dummy(0);
        ListNode* current = &dummy;

        // 持续从堆中取出最小值节点
        // Continuously extract the minimum value node from heap
        while (!pq.empty()) {
            // 取出最小值节点
            // Extract the minimum value node
            ListNode* minNode = pq.top();
            pq.pop();

            // 将最小值节点连接到结果链表
            // Connect the minimum value node to result linked list
            current->next = minNode;
            current = current->next;

            // 如果该节点还有下一个节点，将其加入堆中
            // If this node has a next node, add it to the heap
            if (minNode->next != nullptr) {
                pq.push(minNode->next);
            }
        }

        return dummy.next;
    }

    // 方法2：分治法（递归合并）
    // Method 2: Divide and conquer approach (recursive merge)
    ListNode* mergeKListsDivideConquer(vector<ListNode*>& lists) {
        // 边界条件检查
        // Boundary condition check
        if (lists.empty()) return nullptr;
        if (lists.size() == 1) return lists[0];

        return mergeKListsHelper(lists, 0, lists.size() - 1);
    }

private:
    // 递归辅助函数：合并指定范围内的链表
    // Recursive helper function: merge linked lists within specified range
    ListNode* mergeKListsHelper(vector<ListNode*>& lists, int start, int end) {
        // 基础情况：只有一个链表
        // Base case: only one linked list
        if (start == end) return lists[start];

        // 基础情况：两个链表
        // Base case: two linked lists
        if (start + 1 == end) {
            return mergeTwoLists(lists[start], lists[end]);
        }

        // 分治：将问题分解为两个子问题
        // Divide and conquer: split problem into two subproblems
        int mid = start + (end - start) / 2;
        ListNode* left = mergeKListsHelper(lists, start, mid);
        ListNode* right = mergeKListsHelper(lists, mid + 1, end);

        return mergeTwoLists(left, right);
    }

    // 合并两个有序链表的辅助函数
    // Helper function to merge two sorted linked lists
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // 边界条件：其中一个链表为空
        // Boundary condition: one of the linked lists is null
        if (!l1) return l2;
        if (!l2) return l1;

        // 虚拟头节点简化边界处理
        // Dummy head node to simplify boundary handling
        ListNode dummy(0);
        ListNode* current = &dummy;

        // 比较两个链表的节点值，选择较小者
        // Compare node values of two linked lists, choose the smaller one
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                current->next = l1;
                l1 = l1->next;
            } else {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }

        // 连接剩余的节点
        // Connect remaining nodes
        current->next = l1 ? l1 : l2;

        return dummy.next;
    }
};
