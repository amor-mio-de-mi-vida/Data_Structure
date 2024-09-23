#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
} TreeNode;


class Solution {
public:
    //中序遍历 左-根-右
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)
            return {};
        
        stack<TreeNode*> stk;
        vector<int> res;
        while(root || !stk.empty()){
            while(root){
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            res.emplace_back(root->val);

            root = root->right;
        }
        return res;
    }
};
