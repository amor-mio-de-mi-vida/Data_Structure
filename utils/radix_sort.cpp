#include "../include/sort.h"

void radix_sort_LSD(int* array, int size) {
    if (array==nullptr) return;
    int max = 0;
    for (int i = 0; i < size; i++) {
        if (abs(array[i]) > max) {
            max = abs(array[i]);
        }
    }

    int maxDigitLength = 0;
    while (max != 0) {
        maxDigitLength++;
        max /= 10;
    }

    int* counting = (int*)malloc(sizeof(int)*19);
    int* result = (int*)malloc(sizeof(int)*size);
    int dev = 1;
    for (int i = 0; i < maxDigitLength; i++) {
        for (int j = 0; j < size; j++) {
            int radix = array[j] / dev % 10 + 9;
            counting[radix]++;
        }
        for (int j = 1; j < 19; j++) {
            counting[j] += counting[j-1];
        }
        for (int j = size - 1; j >= 0; j--) {
            int radix = array[j] / dev % 10 + 9;
            result[--counting[radix]] = array[j];
        }

        for (int i = 0; i < size; i++) {
            array[i] = result[i];
        }

        for (int i = 0; i < 19; i++) {
            counting[i] = 0;
        }

        dev *= 10;
    }
}

void radixSort(int* array, int start, int end, int position) {
    if (start == end || position == 0) return;
    int* counting = (int*)malloc(sizeof(int) * 19);
    int* result = (int*)malloc(sizeof(int) * (end - start + 1));
    int dev = (int) pow(10, position - 1);
    for (int i = start; i <= end; i++) {
        int radix = array[i] / dev % 10 + 9;
        counting[radix]++;
    }
    for (int j = 1; j < 19; j++) {
        counting[j] += counting[j - 1];
    }
    int* countingCopy = (int*)malloc(sizeof(int) * 19);
    for (int i = 0; i < 19; i++) {
        countingCopy[i] = counting[i];
    }
    for (int i = end; i >= start; i--) {
        int radix = array[i] / dev % 10 + 9;
        result[--counting[radix]] = array[i];
    }
    for (int i = start; i <= end; i++) {
        array[i] = result[i-start];
    }
    free(counting);
    free(result);
    for (int i = 0; i < 19; i++) {
        radixSort(array, i == 0 ? start : start + countingCopy[i - 1], start + countingCopy[i] - 1, position - 1);
    }
    free(countingCopy);
}


void radix_sort_MSD(int* array, int size) {
    if (array == nullptr) return;
    int max = 0;
    for (int i = 0; i < size; i++) {
        if (abs(array[i]) > max) {
            max = abs(array[i]);
        }
    }
    int maxDigitLength = 0;
    while (max != 0) {
        maxDigitLength++;
        max /= 10;
    }
    radixSort(array, 0, size - 1, maxDigitLength);
}

void radix_sort(int* array, int size, const char* mode) {
    if (!strcmp(mode, "MSD")) {
        radix_sort_MSD(array, size);
    } else if (!strcmp(mode, "LSD")) {
        radix_sort_LSD(array, size);
    } else {
        cout << "Error, not the correct mode!" << endl;
    }
}