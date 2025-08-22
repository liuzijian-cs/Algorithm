/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 思路：
// 肯定是得基于哈希表（查找O（1）），然后再做一个队列？用来移除？

// 哈希表 + 双向链表 的组合
// 哈希表：存储key到链表节点的映射，实现O(1)查找
// 双向链表：维护访问顺序，头部是最新访问的，尾部是最久未使用的

// LRU 的核心需求 (Core Requirements of LRU)
// LRU 缓存需要支持三类操作，并且都要 O(1) 完成：
// 1. 在任意位置删除节点
// 1.1 当访问某个 key 时，需要把它对应的节点移到最前面（代表最近使用）
// 1.2 这意味着节点可能在链表中间，要快速删除。
// 2. 在头部插入节点：新加入的或刚被访问的 key，需要放到队列头。
// 3. 在尾部删除节点：当容量满时，要淘汰最久未使用的节点（队尾）。
// 如果用标准队列：如果要把某个中间元素移到队头，必须遍历整个队列才能找到并删除它 → O(n)。
// 双向链表可以，O(1) 在任意位置删除节点，O(1) 在头部插入 / 尾部删除





class LRUCache {
public:
    // 构造函数，初始化缓存容量
    LRUCache(int capacity) ;
    // 获取键对应的值
    int get(int key) ;
    //  插入或更新键值对
    void put(int key, int value) ;

private:
    struct Node{
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k=0, int v=0):key(k), value(v), prev(nullptr), next(nullptr){}
    };
    int _capacity;  // 缓存容量
    unordered_map<int, Node*> _cache; // hashmap
    Node* _head;  // 双向链表的头部（Dummy head node）
    Node* _tail;  // 双向链表的尾部（Dummy head node）

    // Add node at the head of the linked list
    void add_to_head(Node* node);
    // Remove specified node from the linked list
    void remove_node(Node* node);
    // Move the specified node to the head of the linked list
    void move_to_head(Node* node) ;
    // Remove the tail node from the linked list
    Node* remove_tail() ;
};

LRUCache::LRUCache(int capacity): _capacity(capacity){
    _head = new Node();  // Dummy head node
    _tail = new Node();  // Dummy tail node
    _head->next = _tail; // Initialize the linked list
    _tail->prev = _head;
}

void LRUCache::add_to_head(Node* node){
    node->next = _head->next; // Insert after head
    node->prev = _head;
    _head->next->prev = node; // Update next node's prev
    _head->next = node;       // Update head's next to new node
}

void LRUCache::remove_node(Node* node){
    node->prev->next = node->next; // Bypass the node
    node->next->prev = node->prev;
}

void LRUCache::move_to_head(Node* node) {
    remove_node(node); // Remove from current position
    add_to_head(node); // Add to head
}

LRUCache::Node* LRUCache::remove_tail() {
    Node* tail = _tail->prev; // Get the last real node
    remove_node(tail);        // Remove it from the list
    return tail;              // Return the removed node
}

int LRUCache::get(int key) {
    auto it = _cache.find(key);
    if(it == _cache.end()) return -1; // Key not found
    move_to_head(it->second); // Move accessed node to head
    return it->second->value; // Return the value
}

void LRUCache::put(int key, int value) {
    auto it = _cache.find(key);
    if(it != _cache.end()) {
        // Key exists, update value and move to head
        it->second->value = value;
        move_to_head(it->second);
    } else {
        // Key does not exist, create new node
        Node* newNode = new Node(key, value);
        if(_cache.size() >= _capacity) {
            // Capacity exceeded, remove LRU item
            Node* tail = remove_tail();
            _cache.erase(tail->key); // Remove from hashmap
            delete tail;             // Free memory
        }
        _cache[key] = newNode; // Add to hashmap
        add_to_head(newNode);  // Add to linked list
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

