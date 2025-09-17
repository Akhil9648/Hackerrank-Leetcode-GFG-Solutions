/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*>mp;
    void bfs(TreeNode* node,TreeNode* parent){
        if(node!=NULL){
            mp[node]=parent;
            bfs(node->left,node);
            bfs(node->right,node);
        }
        return;
    }
    void find(TreeNode* target,vector<int>& ans,int k){
        queue<TreeNode*>q;
        unordered_set<TreeNode*>st;
        q.push(target);
        st.insert(target);
        int s=q.size();
        while(k-- && !q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                TreeNode* a=q.front();
                q.pop();
                if(a->left && st.find(a->left)==st.end()){
                    TreeNode* b=a->left;
                    q.push(b);
                    st.insert(b);
                }
                if(a->right && st.find(a->right)==st.end()){
                    TreeNode* b=a->right;
                    q.push(b);
                    st.insert(b);

                }
                if(mp[a]!=NULL && st.find(mp[a])==st.end()){
                    q.push(mp[a]);
                    st.insert(mp[a]);
                }
            }
        }
        while(!q.empty()){
            TreeNode* a=q.front();
            q.pop();
            ans.push_back(a->val);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*>q;
        q.push(root);
        vector<int>ans;
        bfs(root,NULL);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node==target){
                find(target,ans,k);
                break;
            }
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        return ans;
    }
};