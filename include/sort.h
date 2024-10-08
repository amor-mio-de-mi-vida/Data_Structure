#include "header.h"

#ifndef _SORT_H
#define _SORT_H

void swap(int& a, int& b);

void sort_by_stride(int* array, int size, int begin, int stride);

//冒泡排序
void bubble_sort_simple(int* array, int size);
void bubble_sort_flag(int* array, int size);
void bubble_sort_pos(int*array, int size);
void bubble_sort(int* array, int size, const char* mode);

//选择排序
void select_sort_simple(int* array, int size);
void select_sort_binary(int* array, int size);
void select_sort(int* array, int size, const char* mode);

//插入排序
void insert_sort_swap(int* array, int size);
void insert_sort_move(int* array, int size);
void insert_sort(int* array, int size, const char* mode);

//希尔排序
void shell_sort_simple(int* array, int size);
void shell_sort_sequence(int* array, int size);
void shell_sort_knuth(int* array, int size);
void shell_sort(int* array, int size, const char* mode);

//堆排序
void build_max_heap(int* array, int size);
void heap_sort(int* array, int size);
void modify_max_heap(int* array, int i, int size);

//快速排序
void quick_sort(int* array, int size);
void quick_sort(int* array, int start, int end); 
int partition_diy(int* array, int start, int end);

//归并排序
void merge(int* array, int start, int end, int* buffer);
void merge_sort(int* array, int start, int end, int* buffer);
void merge_sort(int* array, int size);

// 计数排序
void counting_sort(int* array, int size);
void counting_sort2(int* array, int size);

// 基数排序
void radix_sort_LSD(int* array, int size);
void radixSort(int* array, int start, int end, int position);
void radix_sort_MSD(int* array, int size);
void radix_sort(int* array, int size, const char* mode);

#endif