#include "header.h"


#ifndef _DS_H
#define _DS_H

template <class T>
class MyLinkedList {
public:
    struct node{
        T val;
        node* next;
        node(T x) : val(x), next(nullptr) {}
    };

    MyLinkedList();
    int get(int index); 
    void addAtHead(T val);
    void addAtTail(T val);
    void addAtIndex(int index, T val);
    void deleteAtIndex(int index);
    void debug();

    int get_size() {return size;}

private:
    int size;
    node* head;
};

template <class T>
class Stack {
    Stack();
    void push(int x);
    bool is_empty();
    int top();
    bool pop();
    void debug();

    vector<T> get_data() {return data;};

private:
    vector<T> data;
};

template <class T>
class Queue {
public:
    Queue(int k);

    bool is_empty();
    bool is_full();
    bool en_queue(int value);
    bool de_queue();
    int get_front();
    int get_rear();

    void debug();
    int get_size() {return size;}
    int get_head() {return head;}
    int get_tail() {return tail;}
    vector<T> get_queue() {return queue;}

private:
    vector<T> queue;
    int size;
    int head;
    int tail;
};


class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    
    int child_count;
    int layer;

    TreeNode() : val(0), left(nullptr), right(nullptr) ,child_count(0), layer(0) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) ,child_count(0), layer(0) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {
        child_count = left != nullptr? 1 : 0 + right != nullptr? 1 : 0;
        left->layer = layer + 1;
        right->layer = layer + 1;
    } 

    void debug();
};


#endif