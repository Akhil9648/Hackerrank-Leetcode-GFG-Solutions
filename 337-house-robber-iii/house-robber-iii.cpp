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
    pair<int,int>solve(TreeNode* root){
        if(!root){
            return {0,0};
        }
        pair<int,int>a=solve(root->left);
        pair<int,int>b=solve(root->right);
        int nr=max(a.second,a.first)+max(b.second,b.first);
        return {nr,root->val+a.first+b.first};
    }
    int rob(TreeNode* root) {
        pair<int,int> it=solve(root);
        return max(it.second,it.first);

    }
};