#include "../include/sort.h"

void counting_sort(int* array, int size) {
    if (array == nullptr || size <= 1) return;
    int max = array[0];
    int min = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) max = array[i];
        else if (array[i] < min) min = array[i];
    }

    int range = max - min + 1;
    int* counting = (int*)malloc(sizeof(int) * range);
    for (int i = 0; i < size; i++) {
        counting[array[i]-min]++;
    }

    int preCounts = 0;
    for (int i = 0; i < range; i++) {
        preCounts += counting[i];
        counting[i] = preCounts - counting[i];
    }
    int* result = (int*)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        result[counting[array[i]-min]] = array[i];
        counting[array[i] - min]++;
    }

    for(int i = 0; i < size; i++) {
        array[i] = result[i];
    }
    free(result);
    free(counting);
}

void counting_sort2(int* array, int size) {
    if (array == nullptr || size <= 1) return;
    int max = array[0];
    int min = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) max = array[i];
        else if (array[i] < min) min = array[i];
    }

    int range = max - min + 1;
    int* counting = (int*)malloc(sizeof(int) * range);
    for (int i = 0; i < size; i++) {
        counting[array[i]-min]++;
    }

    counting[0]--;
    for (int i = 1; i < range; i++) {
        counting[i] += counting[i-1];
    }
    int* result = (int*)malloc(sizeof(int) * size);
    for (int i = size - 1; i >= 0; i--) {
        result[counting[array[i] - min]] = array[i];
        counting[array[i] - min]--;
    }
    for (int i = 0; i < size; i++) {
        array[i] = result[i];
    }
    free(result);
    free(counting);
}