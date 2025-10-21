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
    void good(TreeNode* root,int maxi,int &count){
        if(!root) return;
        if(root->val>=maxi) count++;
        maxi=max(maxi,root->val);
        good(root->left,maxi,count);
        good(root->right,maxi,count);
    }
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        int count=0;
        good(root,root->val,count);
        return count;
    }
};