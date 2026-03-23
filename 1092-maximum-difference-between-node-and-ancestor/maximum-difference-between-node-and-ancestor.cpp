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
    int ans=0;
    void solve(TreeNode* root,int maxi,int mini){
        if(!root) return;
        maxi=max(maxi,root->val);
        mini=min(mini,root->val);
        if(root->left) solve(root->left,maxi,mini);
        if(root->right) solve(root->right,maxi,mini);
        ans=max(ans,(maxi-mini));
    }
    int maxAncestorDiff(TreeNode* root) {
        solve(root,0,INT_MAX);
        return ans;
    }
};