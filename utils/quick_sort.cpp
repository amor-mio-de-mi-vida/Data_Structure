#include "../include/sort.h"
#include "../include/utils.h"

void quick_sort(int* array, int size) {
    quick_sort(array, 0, size - 1);
}

void quick_sort(int*array, int start, int end) {
    if (start >= end) return; 
    int middle = partition_diy(array, start, end);
    quick_sort(array, start, middle - 1);
    quick_sort(array, middle + 1, end);
}

int partition_diy(int* array, int start, int end) {
    int key = get_rand(start, end);
    while(start < key || end > key) {
        if (start < key && end > key) {
            while (start < key && array[start] <= array[key]) start++;
            while (end > key && array[end] >= array[key]) end--;
            if (start < key && end > key) {
                swap(array[start], array[end]);
                start++;
                end--;
            }
            continue;
        } else if (start >= key && end > key) {
            while (end > key && array[end] >= array[key]) end--;
            if (end > key) {
                swap(array[key], array[end]);
                key = end;
            }
            continue;
        } else if (start < key && end <= key) {
            while (start < key && array[start] <= array[key]) start++;
            if (start < key) {
                swap(array[key], array[start]);
                key = start;
            }
            continue;
        }
    }
    return key;
}