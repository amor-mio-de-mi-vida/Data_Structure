#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int* base;
    int front;
    int rear;
    int num, size;
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    if(!obj) return NULL;
    obj->base = (int*)malloc(k*sizeof(int));
    obj->front = obj->rear = 0;
    obj->num = 0;
    obj->size = k;
    return obj;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj)) {
        return false;
    }
    obj->rear = (obj->rear + 1) % obj->size;
    obj->base[obj->rear] = value;
    obj->num++;
    if (obj->num == 1) 
        obj->front=obj->rear;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) {
        return false;
    }
    obj->base[obj->front] = -1;
    obj->front = (obj->front + 1)%(obj->size);
    obj->num--;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) {
        return -1;
    }
    return obj->base[obj->front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) {
        return -1;
    }
    return obj->base[obj->rear];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return(obj->num==0);
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return(obj->num==obj->size);
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->base);
    obj->base=NULL;
    free(obj);
    obj=NULL;
}

