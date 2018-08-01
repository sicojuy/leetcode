/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void getLeafs(TreeNode* root, int* leafs, int* len) {
    if (root->left == NULL && root->right == NULL) {
        leafs[(*len)++] = root->val;
        return;
    }
    if (root->left != NULL) {
        getLeafs(root->left, leafs, len);
    }
    if (root->right != NULL) {
        getLeafs(root->right, leafs, len);
    }
}

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        int leafs1[100], leafs2[100];
        int l1, l2;
        l1 = l2 = 0;
        getLeafs(root1, leafs1, &l1);
        getLeafs(root2, leafs2, &l2);
        if (l1 != l2) {
            return false;
        }
        for (int i = 0; i < l1; i++) {
            if (leafs1[i] != leafs2[i]) {
                return false;
            }
        }
        return true;
    }
};