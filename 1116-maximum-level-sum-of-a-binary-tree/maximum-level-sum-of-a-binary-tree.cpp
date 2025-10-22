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
    int maxLevelSum(TreeNode* root) {
        int cnt=0,maxi=INT_MIN,curr=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            curr++;
            int n=q.size();
            int sm=0;
            for(int i=0;i<n;i++){
                TreeNode* a=q.front();
                q.pop();
                sm+=a->val;
                if(a->left) q.push(a->left);
                if(a->right) q.push(a->right);
            }
            if(sm>maxi){
                maxi=sm;
                cnt=curr;
            }
        }
        return cnt;
    }
};