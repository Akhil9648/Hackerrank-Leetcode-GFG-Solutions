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
    vector<TreeNode* >preorder;
    void pre(TreeNode* root){
        if(!root) return;
        preorder.push_back(root);
        if(root->left) pre(root->left);
        if(root->right) pre(root->right);
    }
    void flatten(TreeNode* root) {
        pre(root);
        TreeNode* ptr=root;
        for(int i=1;i<preorder.size();i++){
            ptr->left=NULL;
            ptr->right=preorder[i];
            ptr=ptr->right;
        }
    }
};