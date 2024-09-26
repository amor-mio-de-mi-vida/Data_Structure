#include "../include/ds.h"

template <class T>
Queue<T>::Queue(int k) : size(k), head(-1), tail(-1) {
    queue.reserve(k);
}

template <class T>
bool Queue<T>::is_empty() {
    return size == 0;
}

template <class T>
bool Queue<T>::is_full() {
    return (tail + 1) % size == head;
}


template <class T>
bool Queue<T>::en_queue(int value) {
    if(is_empty()) {
        head++;
        tail++;
        queue[tail] = value;
        return true;
    } else if (is_full()) return false;
    tail = (tail + 1) % size;
    queue[tail] = value;
    return true;
}

template <class T>
bool Queue<T>::de_queue() {
    if (is_empty()) return false;
    if (head == tail) {
        head = -1; 
        tail = -1;
        return true;
    }
    head = (head + 1) % size;
    return true;
}

template <class T>
int Queue<T>::get_front()  {
    if (is_empty()) return -1;
    return queue[head];
}

template <class T>
int Queue<T>::get_rear()  {
    if (is_full()) return -1;
    return queue[tail];
}

template <class T>
void Queue<T>::debug() {
    printf("DEBUG: Queue: head = %d, tail = %d, size = %d\n", get_head(), get_tail(), get_size());
    for (int i = 0; i < get_size(); i++) {
        if (i != get_tail()) {
            cout << get_queue()[(i+head)%size] << " ";
        } else { 
            cout << get_queue()[(i+head)%size] << endl;
            break;
        }
    }
}