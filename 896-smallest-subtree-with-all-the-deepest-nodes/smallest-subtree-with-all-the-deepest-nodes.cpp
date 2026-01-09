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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root) return NULL;
        unordered_map<TreeNode*,TreeNode*>parent;
        queue<TreeNode*>q;
        vector<TreeNode*>ll;
        q.push(root);
        parent[root]=NULL;
        while(!q.empty()){
            int n=q.size();
            int size=q.size();
            ll.clear();
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                ll.push_back(node);
                q.pop();
                if(node->left){
                    q.push(node->left);
                    parent[node->left]=node;
                }
                if(node->right){
                    q.push(node->right);
                    parent[node->right]=node;
                }
            }
        }
            unordered_set<TreeNode*>last(ll.begin(),ll.end());
            while(last.size()>1){
                unordered_set<TreeNode*>nxt;
                for(auto node:last){
                    nxt.insert(parent[node]);
                }
                last=nxt;
            }
        return *last.begin();
    }
};