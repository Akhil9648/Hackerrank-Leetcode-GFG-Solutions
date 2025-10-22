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
    void solve(TreeNode* root,int &count,int flag,int curr){
        if(!root) return;
        count=max(count,curr);
        if(!flag){
            solve(root->right,count,1,curr+1);
            solve(root->left,count,0,1);
        }
        else{
            solve(root->left,count,0,curr+1);
            solve(root->right,count,1,1);
        }
    }
    int longestZigZag(TreeNode* root) {
        int count=0;
        solve(root->left,count,0,1);
        solve(root->right,count,1,1);
        return count;
    }
};