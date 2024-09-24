#include "../include/sort.h"

void sort_by_stride(int* array, int size, int begin, int stride) {
    for (int index = begin + stride; index < size; index += stride) {
        int temp_index = index;
        while (array[temp_index] < array[temp_index - stride] && temp_index >= stride) {
            swap(array[temp_index], array[temp_index - stride]);
            temp_index -= stride;
        }
    }
}