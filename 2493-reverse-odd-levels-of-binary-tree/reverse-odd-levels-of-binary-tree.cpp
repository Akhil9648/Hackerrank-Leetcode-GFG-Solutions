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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode* >q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            int n=q.size();
            vector<TreeNode*>vec;
            while(n--){
                auto it=q.front();
                vec.push_back(it);
                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);
                q.pop();
            }
            if(level%2){
                int n=vec.size();
                int i=0,j=n-1;
                while(i<j){
                    swap(vec[i]->val, vec[j]->val);
                    i++;
                    j--;
                }
            }
            level++;
        }
        return root;
    }
};