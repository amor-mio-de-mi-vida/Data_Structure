#include "../include/sort.h"

void select_sort_simple(int* array, int size) {
    int minIndex;
    for (int i = 0; i < size - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (array[minIndex] > array[j]) {
                minIndex = j;
            }
        }
        swap(array[i], array[minIndex]);
    }
}

void select_sort_binary(int* array, int size) {
    int minIndex, maxIndex;
    for (int i = 0; i < size / 2; i++) {
        minIndex = i;
        maxIndex = i;
        for (int j = i + 1; j < size - i; j++) {
            if (array[minIndex] > array[j]) {
                minIndex = j;
            } 
            if (array[maxIndex] < array[j]) {
                maxIndex = j;
            }
        }
        if (minIndex == maxIndex) break;
        swap(array[i], array[minIndex]);
        if (maxIndex == i) maxIndex = minIndex;
        swap(array[maxIndex], array[size - i - 1]);
    }
}

void select_sort(int* array, int size, const char* mode) {
    if (!strcmp(mode, "simple")) {
        select_sort_simple(array, size);
    } else if (!strcmp(mode, "binary")) {
        select_sort_binary(array, size);
    }
}