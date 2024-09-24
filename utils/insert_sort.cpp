#include "../include/sort.h"

void insert_sort_swap(int* array, int size) {
    for (int i = 1; i < size; i++) {
        int j = i;
        while (array[j] < array[j-1] && j >= 1) {
            swap(array[j], array[j-1]);
            j--;
        }
    }
}

void insert_sort_move(int* array, int size) {
    for (int i = 1; i < size; i++) {
        int j = i;
        int temp = array[j];
        while (j >= 1 && temp < array[j - 1]) {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = temp;
    }
}

void insert_sort(int* array, int size, const char* mode) {
    if (!strcmp(mode, "swap")) {
        insert_sort_swap(array, size); 
    } else if (!strcmp(mode, "move")) {
        insert_sort_move(array, size);
    } else {
        cout << "Error, not the correct mode!" << endl;
    }
}