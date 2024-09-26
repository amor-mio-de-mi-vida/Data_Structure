#include "../include/ds.h"

template <class T>
MyLinkedList<T>::MyLinkedList() {
    head = new node(0);
    size = 0;
}

template <class T>
void MyLinkedList<T>::addAtHead(T val) {
    node* new_node = new node(val);
    new_node->next = head->next;
    head->next = new_node;
    size++;
}

template <class T>
void MyLinkedList<T>::addAtTail(T val) {
    node* cur = this->head;
    while(cur->next) cur = cur->next;
    node* new_node = new node(val);
    cur->next = new_node;
    size++;
}

template <class T>
void MyLinkedList<T>::addAtIndex(int index, T val) {
    if (index <= 0) addAtHead(val);
    else if (index == size) addAtTail(val);
    else if (index > size) return;
    else {
        node* cur = this->head;
        node* new_node = new node(val);
        while(index--) cur = cur->next;
        new_node->next = cur->next;
        cur->next = new_node;
        size++;
    }
}

template <class T>
int MyLinkedList<T>::get(int index) {
    if(index < 0 || index > size - 1) return -1;
    node *cur = head->next;
    while (index--) {
        cur=cur->next;
    }
    return cur->val;
}

template <class T>
void MyLinkedList<T>::deleteAtIndex(int index) {
    if (index >= size || index < 0) return;
    node* cur = head;
    while(index--) cur = cur->next;
    cur->next = cur->next->next;
    size--;
}

template <class T>
void MyLinkedList<T>::debug() {
    node* cur = head->next;
    printf("DEBUG: MyLinkedList: , size is %d\n", get_size());
    int num = size;
    while(num--) {
        printf("%d ", cur->val);
        cur = cur->next;
    }
    printf("\n");
}