#include "header.h"

#ifndef _GENERATE_H
#define _GENERATE_H


void printHelloWorld();
int get_rand(int min, int max);
vector<int> get_array(int min, int max, int num);
string get_string(const char* str, int num);
vector<int> get_sequence(int begin, int COUNT, bool is_shuffle);

int* vec2array(vector<int> vec);
vector<int> array2vec(int* array, int size);

#endif