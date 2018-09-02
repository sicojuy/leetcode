#include <iostream>
using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode *tmp;
        if (root == NULL) return root;        
        if (root->left == NULL) {
            root->right = increasingBST(root->right);
            return root;
        }
        root->left = increasingBST(root->left);
        tmp = root->left;
        root->left = tmp->right;
        tmp->right = root;
        tmp->right = increasingBST(root);
        return tmp;
    }
};