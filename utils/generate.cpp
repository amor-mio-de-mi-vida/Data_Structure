#include "../include/generate.h"
#include "../include/print.h"

void printHelloWorld() {
    cout << "Hello world!" << endl;
}

int get_rand(int min, int max) {
    return rand() % (max - min + 1) + min;
}

/** 
 * @brief 生成vector<int>
 * @param min 元素的最小值  
 * @param max 元素的最大值 注意是左闭右闭区间
 * @param num vector的长度
 *
 * @return 返回随机的vector
 *     
 */
vector<int> get_array(int min, int max, int num) {
    vector<int> result;
    for (int i = 0; i < num; i++) {
        int r = get_rand(min, max);
        result.push_back(r);
    }
    cout << "generate array" << endl;
    print(result);
    return result;
}

vector<vector<int>> get_matrix(int min, int max, int m, int n) {
    vector<vector<int>> result;
    for (int i = 0; i < m; i++) {
        result.push_back(get_array(min, max, n));
    }
    return result;
}

string get_string(const char* str, int num) {
    string result;
    int len = strlen(str);
    for (int i = 0; i < num; i++) {
        int r = get_rand(0, len-1);
        result += str[r];
    }
    return result;
}

vector<int> get_sequence(int begin, int COUNT, bool is_shuffle) {
    vector<int> ids =  [&begin, COUNT]() {
        vector<int> v;
        v.resize(COUNT);
        for (int i = 0; i < COUNT; i++) {
            v[i] = begin+i;
        }
        return v;
    } ();
    if (is_shuffle) {
        random_device rd;
        mt19937 g(rd());
        shuffle(ids.begin(), ids.end(), g);
    }
    return ids;
}

int* vec2array(vector<int> vec) {
    int* array = (int*)malloc(sizeof(int) * vec.size());
    memcpy(array, &vec[0], sizeof(int) * vec.size());
    return array;
}

vector<int> array2vec(int* array, int size) {
    return vector<int>(array, array + size);
}