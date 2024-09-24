#include "../include/utils.h"
#include "../include/sort.h"
#include "../include/my_assert.h"


int main() {

    srand((unsigned int)time(NULL));
    int rand = get_rand(10, 20);
    printf("rand number is %d\n", rand);
    int size = get_rand(50, 100);

    int* input = (int*)malloc(sizeof(int) * size);
    int* output = (int*)malloc(sizeof(int) * size);

    for (int i = 0; i < rand; i++) {  
        vector<int> array = get_sequence(0, size, true); 
        if(!array.empty()) {
            memcpy(input, &array[0], sizeof(int) * array.size());
            sort(array.begin(), array.end());
            memcpy(output, &array[0], sizeof(int) * array.size());
        }
        // printf("input array is ");
        // print(input, size);

        // bubble_sort(input, array.size(), "flag");
        // select_sort(input, array.size(), "binary");
        // insert_sort(input, size, "swap");
        // shell_sort(input, size, "knuth");
        // heap_sort(input, size);
        // quick_sort(input, size);
        merge_sort(input, size);


        // printf("sorted array is ");
        // print(input, size);

        assert_array(input, output, array.size());
    }

    free(input);
    free(output);

    return 0;
}