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
    map<int,vector<int>>mp;
    void trav(TreeNode* node,int level){
        mp[level].push_back(node->val);
        if(node->left){
            trav(node->left,level+1);
        }
        if(node->right){
            trav(node->right,level+1);
        }
        return ;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        trav(root,0);
        vector<vector<int>>ans;
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};