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
    int maxi=0;
    int height(TreeNode* root){
        if(!root) return 0;
        int lh=0,rh=0;
        if(root->left) lh=height(root->left);
        if(root->right) rh=height(root->right);
        maxi=max(maxi,(lh+rh));
        return max(lh,rh)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int a=height(root);
        return maxi;
    }
};