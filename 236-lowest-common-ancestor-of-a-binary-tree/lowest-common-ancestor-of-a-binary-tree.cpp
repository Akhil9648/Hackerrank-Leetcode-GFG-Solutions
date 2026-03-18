/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* find(TreeNode* p,TreeNode* q,TreeNode* root){
        if(!root || root==p || root==q) return root;
        TreeNode* lr=find(p,q,root->left);
        TreeNode* rr=find(p,q,root->right);
        if(lr!=NULL && rr!=NULL) return root;
        else if(lr!=NULL) return lr;
        else if(rr!=NULL) return rr;
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return find(p,q,root);
    }
};