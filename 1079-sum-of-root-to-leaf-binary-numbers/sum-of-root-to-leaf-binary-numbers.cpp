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
    vector<vector<int>>ans;
    void trav(TreeNode* root,vector<int>curr){
        curr.push_back(root->val);
        if(root->left) trav(root->left,curr);
        if(root->right) trav(root->right,curr);
        if(!root->left && !root->right)ans.push_back(curr);
        return ;
    }
    int conv(vector<int>& s){
        int u=0;
        int n=s.size();
        int ans=0;
        for(int i=n-1;i>=0;i--){
            ans+=pow(2,u)*(s[i]);
            u++;
        }
        return ans;
    }
    int sumRootToLeaf(TreeNode* root) {
        int sum=0;
        vector<int>curr;
        trav(root,curr);
        for(auto it:ans){
            sum+=conv(it);
        }
        return sum;
    }
};