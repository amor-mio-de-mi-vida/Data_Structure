#include "./include/utils.h"
#include "./include/binary_tree.h"
#include "./include/my_assert.h"


int get_max_index(const vector<int>& array) {
    int max = array[0];
    int index = 0;
    for (int i = 1; i < array.size(); i++) {
        if (max < array[i]) {
            max = array[i];
            index = i;
        }
    }
    return index;
}

TreeNode* construct(const vector<int>& array, int begin, int end) {
    if (begin > end || begin < 0 || end > array.size() - 1) {
        return nullptr;
    } else if (begin == end) {
        return new TreeNode(array[begin]);
    } else {
        int max_index = get_max_index(array);
        TreeNode* root = new TreeNode(array[max_index]);
        root->left = construct(array, begin, max_index - 1);
        root->right = construct(array, max_index + 1, end);
        return root;
    }
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return construct(nums, 0, nums.size()-1);
}


int main() {

    

    printHelloWorld();
    return 0;
}