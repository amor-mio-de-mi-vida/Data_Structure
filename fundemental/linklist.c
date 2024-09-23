#include <stdio.h>
#include <stdlib.h>

typedef struct MyLinkedList{
    int val;
    struct MyLinkedList* next;
} MyLinkedList;

MyLinkedList* myLinkedListCreate() {
    MyLinkedList* node = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    node->next = NULL;
    return node;
}

// 这种链表头节点没有数据
int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0) return -1;
    MyLinkedList* node = obj;
    for (int i = 0; i <= index; i++) {
        if (node->next == NULL) return -1;
        else node = node->next;
    }
    return node->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList* head = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    head->val = val;
    head->next = obj->next;
    obj->next = head;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList* tail = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    tail->val = val;
    tail->next = NULL;
    MyLinkedList* node = obj;
    while(node->next != NULL) {
        node = node->next;
    }
    node->next = tail;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    MyLinkedList* add = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    add->val = val;
    MyLinkedList* node = obj;
    for(int i = 0; i < index; i++) {
        if (node->next == NULL) return;
        node = node->next;
    }
    add->next = node->next;
    node->next = add;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0) return;
    MyLinkedList* node = obj;
    for(int i = 0; i < index; i++) {
        if (node->next == NULL) return;
        node = node->next;
    }
    if (node->next == NULL) return; // 关键，这里node->next有可能是NULL
    MyLinkedList* del = node->next;
    node->next = del->next;
    free(del);
}

void myLinkedListFree(MyLinkedList* obj) {
    MyLinkedList* node = obj;
    MyLinkedList* tmp;
    while(node) {
        tmp = node->next;
        free(node);
        node = tmp;
    }
}

int main() {
    MyLinkedList* p = myLinkedListCreate();
    return 0;
}