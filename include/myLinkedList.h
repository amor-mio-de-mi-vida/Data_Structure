#include "header.h"

#ifndef _MYLINKEDLIST_H
#define _MYLINKEDLIST_H

class MyLinkedList {
public:
    struct node{
        int val;
        node* next;
        node(int x) : val(x), next(nullptr) {}
    };

    MyLinkedList();
    int get(int index); 
    void addAtHead(int val);
    void addAtTail(int val);
    void addAtIndex(int index, int val);
    void deleteAtIndex(int index);
    void debug();

    // debug
    int get_size() {
        return size;
    }
private:
    int size;
    node* head;
};

#endif