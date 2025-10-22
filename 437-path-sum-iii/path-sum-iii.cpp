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
    void dfs(TreeNode* root,long long sum,int &cnt,int target){
        if(!root) return;
        sum+=root->val;
        if(sum==target) cnt++;
        dfs(root->left,sum,cnt,target);
        dfs(root->right,sum,cnt,target);
    }
    void solve(TreeNode* root,int target,int & cnt){
        if(!root) return;
        dfs(root,0,cnt,target);
        solve(root->left,target,cnt);
        solve(root->right,target,cnt);
    }
    int pathSum(TreeNode* root, int targetSum) {
        int cnt=0;
        solve(root,targetSum,cnt);
        return cnt;
    }
};