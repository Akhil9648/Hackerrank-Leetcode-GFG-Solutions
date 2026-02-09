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
    vector<int>arr;
    void inorder(TreeNode* root){
        if(!root) return;
        if(root->left) inorder(root->left);
        arr.push_back(root->val);
        if(root->right) inorder(root->right);
    }
    TreeNode* solve(int l,int r,vector<int>& arr){
        if(l>r) return NULL;
        int mid=(l+r)/2;
        TreeNode* root=new TreeNode(arr[mid]);
        root->left=solve(l,mid-1,arr);
        root->right=solve(mid+1,r,arr);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        int n=arr.size();
        TreeNode* ans=solve(0,n-1,arr);
        return ans;
    }
};