#include "../include/ds.h"

void TreeNode::debug() {
    printf("DEBUG: binary_tree: count: %d", child_count+1);
    Queue<int> queue = Queue<int>(child_count);


    cout << endl;
}
