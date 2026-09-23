/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int height(TreeNode* root) {
        if(root==nullptr) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int max1 = (height(root->left)) + (height(root->right));
        if(root->right && (root->right)->left && (root->right)->right) {
            max1 = max(max1, height((root->right)->left) + (height((root->right)->right)));
        }
        if(root->left && (root->left)->left && (root->left)->right) {
            max1 = max(max1, height((root->left)->left) + (height((root->left)->right)));
        }

        return max1;
    }
};
