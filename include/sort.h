#include "header.h"


void swap(int& a, int& b);

// 冒泡排序
void bubble_sort_simple(int* array, int size);
void bubble_sort_flag(int* array, int size);
void bubble_sort_pos(int*array, int size);
void bubble_sort(int* array, int size, const char* mode);

// 选择排序
void select_sort_simple(int* array, int size);
void select_sort_binary(int* array, int size);
void select_sort(int* array, int size, const char* mode);

//插入排序
void insert_sort_swap(int* array, int size);
void insert_sort_move(int* array, int size);
void insert_sort(int* array, int size, const char* mode);

