//
// Created by alpha on 2025/7/3.
//

// 思路：这个题目的难点在于在复制时随机节点指向的目标节点的地址可能是未知的，我的思路是首先顺序构建链表，在构建链表时先将随机节点的地址存储为旧
// 链表对应的地址。（或者构建一个地址哈希表？旧地址：新地址，但效率会不会优点低）然后再遍历一遍把random的部分做替换


#include<iostream>
#include<unordered_map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// self: 方法2 - 原地地址法
// 21.29% - 95.10%
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head==nullptr) return nullptr;

        // 第一步：插入新节点
        // 原链表: A -> B -> C -> D
        // 变成:   A -> A' -> B -> B' -> C -> C' -> D -> D'

        Node* curr = head;
        while (curr!=nullptr) {
            Node* new_node = new Node(curr->val);
            new_node->next = curr->next;
            curr->next = new_node;
            curr = new_node->next;
        }

        // 设置random指针
        curr = head;
        while (curr!=nullptr) {
            curr->next->random = curr->random == nullptr ? nullptr : curr->random->next;
            curr = curr->next->next;
        }

        // 分离链表
        curr = head;
        Node* new_head = curr->next;
        Node* new_curr = new_head;
        while (curr!=nullptr) {
            curr->next = new_curr->next;

            curr = curr->next; //nullptr

            if (curr && curr->next!=nullptr) new_curr->next = curr->next;
            new_curr = new_curr->next;
        }
        return new_head;
    }
};


// 54.02% - 64.52%
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head==nullptr) return nullptr;
        unordered_map<Node*,Node*> hashmap;

        // First traversal: create all new nodes and establish mapping
        Node* curr = head;
        while (curr!=nullptr) {
            hashmap[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // Second traversal: set next and random pointers for new nodes
        curr = head;
        while (curr!=nullptr) {
            Node* curr_new = hashmap[curr];
            // next
            if (curr->next!=nullptr) curr_new->next = hashmap[curr->next];
            // random
            if (curr->random!=nullptr) curr_new->random = hashmap[curr->random];

            curr = curr->next;
        }
        return hashmap[head];
    }
};


