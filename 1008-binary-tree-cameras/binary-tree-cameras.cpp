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
int count=0;
    int dfs(TreeNode* root){
        if(!root) return 2;
        int ls=dfs(root->left);
        int rs=dfs(root->right);
        if(ls==-1 || rs==-1){
            count+=1;
            return 0;
        }
        if(ls==0 || rs==0) return 1;
        return -1;
    }
    int minCameraCover(TreeNode* root) {
        int a=dfs(root);
        if(a==-1) count++;
        return count;
    }
};