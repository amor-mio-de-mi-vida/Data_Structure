#include "../include/sort.h"


void merge(int* array, int start, int end, int* buffer) {
    int end1 = (start + end) / 2;
    int start2 = end1 + 1;
    int index1 = start;
    int index2 = start2;
    int resultIndex = start;
    while (index1 <= end1 && index2 <= end) {
        if (array[index1] <= array[index2]) {
            buffer[resultIndex++] = array[index1++];
        } else {
            buffer[resultIndex++] = array[index2++];
        }
    }
    while (index1 <= end1) {
        buffer[resultIndex++] = array[index1++];
    }
    while (index2 <= end) {
        buffer[resultIndex++] = array[index2++];
    }
    // memcpy(buffer+start*sizeof(int), array+start*sizeof(int), sizeof(int) * (end - start + 1));
    for (int i = start; i <= end; i++) {
        array[i] = buffer[i];
    }
}


void merge_sort(int* array, int start, int end, int* buffer) {
    if (start == end) return;
    int middle = (start + end) / 2;
    merge_sort(array, start, middle, buffer);
    merge_sort(array, middle + 1, end, buffer);
    merge(array, start, end, buffer);
}


void merge_sort(int* array, int size) {
    if (size == 0) return;
    int* result = (int*)malloc(sizeof(int)*size);
    merge_sort(array, 0, size - 1, result);
    free(result);
}