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
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        // No left child, so follow the right child.
        // If both are NULL, this returns 0 + 1 for the leaf.
        if (root->left == NULL) {
            return minDepth(root->right) + 1;
        }

        // No right child, so follow the left child.
        if (root->right == NULL) {
            return minDepth(root->left) + 1;
        }

        // Both children exist, so take the shorter path to a leaf.
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};