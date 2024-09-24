#include "../include/sort.h"


void modify_max_heap(int* array, int i, int size) {
    int l = 2 * i + 1;
    int r = l + 1;
    int largest = i;
    if (l < size && array[l] > array[largest]) {
        largest = l;
    }
    if (r < size && array[r] > array[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(array[i], array[largest]);
        modify_max_heap(array, largest, size);
    }
}

void build_max_heap(int* array, int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        modify_max_heap(array, i, size);
    }
}

void heap_sort(int* array, int size) {
    build_max_heap(array, size);
    for (int i = size - 1; i > 0; i--) {
        swap(array[0], array[i]);
        modify_max_heap(array, 0, i);
    }
}
