class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        queue<int>q;
        q.push(source);
        vector<int>vis(n);
        while(!q.empty()){
            int node=q.front();
            vis[node]=1;
            q.pop();
            if(node==destination) return true;
            for(auto it:adj[node]){
                if(!vis[it]){
                    q.push(it);
                }
            }
        }
        return false;
    }
};