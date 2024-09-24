#include "../include/sort.h"
 
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void bubble_sort_simple(int* array, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (array[j] > array[j+1]) {
                swap(array[j], array[j+1]);
            }
        }
    }
}

void bubble_sort_flag(int* array, int size) {
    for (int i = 0; i < size - 1; i++) {
        bool flag = true;
        for (int j = 0; j < size - 1; j++) {
            if (array[j] > array[j + 1]) {
                flag = false;
                swap(array[j], array[j+1]);
            }
        }
        if (flag) {
            break;
        }
    }
}

void bubble_sort_pos(int*array, int size) {
    bool swapped = true;
    int lastIndex = size - 1;
    int index = -1;
    while (swapped) {
        swapped = false;
        for (int i = 0; i < lastIndex; i++) {
            if (array[i] > array[i+1]) {
                swap(array[i], array[i+1]);
                swapped = true;
                index = i;
            }
            lastIndex = index;
        }
    }
} 

void bubble_sort(int* array, int size, const char* mode) {
    if (!strcmp(mode, "simple")) {
        bubble_sort_simple(array, size);
    } else if (!strcmp(mode, "flag")) {
        bubble_sort_flag(array, size);
    } else if (!strcmp(mode, "pos")) {
        bubble_sort_pos(array, size);
    } else {
        cout << "Error, not the correct mode!" << endl;
    }
}   
