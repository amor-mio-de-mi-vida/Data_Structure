#include "../include/my_assert.h"


void assert_vector(const vector<int>& a, const vector<int>& b) {
    assert(a.size() == b.size());
    for (int i = 0; i < a.size(); i++) {
        assert(a[i] == b[i]);
    }
    cout << "Correct! two vectors are the same" << endl;
}

void assert_array(int* a, int* b, int size) {
    for (int i = 0; i < size; i++) {
        assert(a[i] == b[i]);
    }
    cout << "Correct! two arrays are the same" << endl;
}