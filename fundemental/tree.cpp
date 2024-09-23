#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

typedef struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
} TreeNode;

void travel(struct TreeNode* root, int* arr, int* size) {
    if (root != NULL) {
        arr[(*size)++] = root->val;
        travel(root->left, arr, size);
        travel(root->right, arr, size);
    }
}

int* preorderTraversal0(struct TreeNode* root, int* returnSize) {
    int* arr = (int*)malloc(100*sizeof(int));
    *returnSize = 0;
    travel(root, arr, returnSize);
    return arr;
}

int* preorderTraversal1(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int *arr = (int*)malloc(100*sizeof(int));
    struct TreeNode *stk[100];
    int stk_top = -1;

    while (stk_top > -1 || root != NULL) {
        while (root != NULL) {
            arr[(*returnSize)++] = root->val;
            stk[++stk_top] = root;
            root = root->left;
        }
        root = stk[stk_top--];
        root = root->right;
    }
    return arr;
}

vector<int> inorderTraversal(TreeNode* root) {
    TreeNode* p = root;
    stack<TreeNode*> stack;
    vector<int> ret;
    if (root != nullptr) {
        while (!stack.empty() || p != nullptr) {
            if (p!= nullptr) {
                stack.push(p);
                p = p->left;
            } else {
                p = stack.top();
                ret.push_back(p->val);

                p = p->right;
            }
        }
    }
    return ret;
}


int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int* myArray = (int*)malloc(sizeof(int) * 100);
    (*returnSize) = 0;
    struct TreeNode* prev = NULL;
    struct TreeNode* treeNodeStack[100];
    int treeNodeStackTop = -1;
    while(root != NULL || treeNodeStackTop > -1) {
        while (root != NULL) {
            treeNodeStack[++treeNodeStackTop] = root;
            root = root->left;
        }
        root = treeNodeStack[treeNodeStackTop];
        root = root->right;
        if (root != NULL && root != prev) {
            continue;
        } else {
            prev = treeNodeStack[treeNodeStackTop];
            myArray[*returnSize] = prev->val;
            (*returnSize)++;
            treeNodeStackTop--;
            root = NULL;
        }
    }
    return myArray;
}