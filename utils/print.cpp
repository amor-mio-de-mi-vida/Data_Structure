#include "../include/print.h"


/** 
 * @brief 打印vector<int>
 * @param array 待打印的vector
 *     
 */
void print(vector<int>& array) {
    for (int i = 0; i < array.size(); i++) {
        if (i != array.size() - 1) {
            cout << array[i] << " ";
        } else {
            cout << array[i] << endl;
        }
    }
}
