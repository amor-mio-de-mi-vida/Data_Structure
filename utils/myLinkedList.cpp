#include "../include/myLinkedList.h"

MyLinkedList::MyLinkedList() {
    head = new node(0);
    size = 0;
}

void MyLinkedList::addAtHead(int val) {
    node* new_node = new node(val);
    new_node->next = head->next;
    head->next = new_node;
    size++;
}

void MyLinkedList::addAtTail(int val) {
    node* cur = this->head;
    while(cur->next) cur = cur->next;
    node* new_node = new node(val);
    cur->next = new_node;
    size++;
}

void MyLinkedList::addAtIndex(int index, int val) {
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

int MyLinkedList::get(int index) {
    if(index < 0 || index > size - 1) return -1;
    node *cur = head->next;
    while (index--) {
        cur=cur->next;
    }
    return cur->val;
}

void MyLinkedList::deleteAtIndex(int index) {
    if (index >= size || index < 0) return;
    node* cur = head;
    while(index--) cur = cur->next;
    cur->next = cur->next->next;
    size--;
}

void MyLinkedList::debug() {
    node* cur = head->next;
    printf("DEBUG: MyLinkedList: ");
    int num = size;
    while(num--) {
        printf("%d ", cur->val);
        cur = cur->next;
    }
    printf("\n");
}