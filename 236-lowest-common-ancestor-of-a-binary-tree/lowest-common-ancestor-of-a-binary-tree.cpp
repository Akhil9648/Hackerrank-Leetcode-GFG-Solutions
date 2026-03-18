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
    TreeNode* find(TreeNode* p,TreeNode* q,TreeNode* root,bool &pf,bool &qf){
        if(!root) return NULL;
        if(root==p) return root;
        if(root==q) return root;
        TreeNode* lr=find(p,q,root->left,pf,qf);
        TreeNode* rr=find(p,q,root->right,pf,qf);
        if(lr!=NULL && rr!=NULL) return root;
        else if(lr!=NULL) return lr;
        else if(rr!=NULL) return rr;
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool pf=false,qf=false;
        return find(p,q,root,pf,qf);
    }
};