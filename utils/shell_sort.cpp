#include "../include/sort.h"

void shell_sort_simple(int* array, int size) {
    for (int gap = size/2; gap > 0; gap /= 2) {
        for (int start = 0; start < gap; start++) {
            sort_by_stride(array, size, start, gap);
        }
    }
}

void shell_sort_sequence(int* array, int size) {
    for (int gap = size/2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int currentNumber = array[i];
            int temp_index = i;
            while(temp_index >= gap && currentNumber < array[temp_index - gap]) {
                array[temp_index] = array[temp_index - gap];
                temp_index -= gap;
            }
            array[temp_index] = currentNumber;
        }
    }
}

void shell_sort_knuth(int* array, int size) {
    int maxKnuthNumber = 1;
    while (maxKnuthNumber * 3 + 1 <= size) {
       maxKnuthNumber = maxKnuthNumber * 3 + 1;
    }

    for (int gap = maxKnuthNumber; gap > 0; gap = (gap-1)/3) {
        for (int i = gap; i < size; i++) {
            int currentNumber = array[i];
            int temp_index = i;
            while (temp_index >= gap && currentNumber < array[temp_index - gap]) {
                array[temp_index] = array[temp_index - gap];
                temp_index -= gap;
            }
            array[temp_index] = currentNumber;
        }
    }
}

void shell_sort(int* array, int size, const char* mode) {
    if (!strcmp(mode, "simple")) {
        shell_sort_simple(array, size);
    } else if (!strcmp(mode, "sequence")) {
        shell_sort_sequence(array, size);
    } else if (!strcmp(mode, "knuth")) {
        shell_sort_knuth(array, size); 
    }
}