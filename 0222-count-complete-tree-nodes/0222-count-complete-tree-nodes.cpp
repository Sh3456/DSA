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
    int countNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int leftHeight = 0;
        for (TreeNode* node = root; node != NULL; node = node->left) {
            leftHeight++;
        }

        int rightHeight = 0;
        for (TreeNode* node = root; node != NULL; node = node->right) {
            rightHeight++;
        }

        if (leftHeight == rightHeight) {
            // 1LL << leftHeight computes 2 raised to leftHeight.
            return (1LL << leftHeight) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};