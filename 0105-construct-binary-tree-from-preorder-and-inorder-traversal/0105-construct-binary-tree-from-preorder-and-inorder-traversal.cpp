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
     TreeNode* build(vector<int>& preorder, vector<int>& inorder, int left, int right, int& i) {
                if(left>right){
                    return nullptr;
                }
                TreeNode*root=new TreeNode(preorder[i]);
                i++;

                int mid=left;
                while(inorder[mid]!=root->val){
                mid++;
                }
                root->left=build(preorder,inorder,left,mid-1,i);
                root->right=build(preorder,inorder,mid+1,right,i);

                return root;

         }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i=0;
        int n=inorder.size();
        return build(preorder,inorder,0,n-1,i);

    }
};