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
    void trav(TreeNode* root,unordered_map<int,int>& mp){
        if(!root) return;
        mp[root->val]++;
        trav(root->left,mp);
        trav(root->right,mp);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int>mp;
        trav(root,mp);
        int maxi=0;
        vector<int>arr;
        for(auto it:mp){
            if(it.second>maxi){
                maxi=it.second;
            }
        }
        for(auto it:mp){
            if(it.second==maxi){
                arr.push_back(it.first);
            }
        }
        return arr;
    }
};