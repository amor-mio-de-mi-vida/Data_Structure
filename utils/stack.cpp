#include "../include/ds.h"

template <class T>
Stack<T>::Stack() {}

template <class T>
void Stack<T>::push(int x) {
    data.push_back(x);
}

template <class T>
bool Stack<T>::is_empty() {
    return data.empty();
}

template <class T>
int Stack<T>::top() {
    return data.back();
}

template <class T>
bool Stack<T>::pop() {
    if (is_empty()) return false;
    data.pop_back();
    return true;
}

template <class T>
void Stack<T>::debug() {
    vector<int> data = get_data();
    printf("DEBUG: Stack: size = %d\n", (int)data.size());
    for (int i = data.size() - 1; i >= 0; i--) {
        if (i != 0) {
            cout << data[i] << " ";
        } else {
            cout << data[i] << "\n";
        }
    }
}