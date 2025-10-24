class Solution {
public:
    void dfs(int i,int p,vector<vector<pair<int,int>>>&adj,vector<int>& vis,int &cnt){
        vis[i]=1;
        for(auto it:adj[i]){
            int j=it.first;
            int chk=it.second;
            if(j!=p && chk==1) cnt++;
            if(!vis[j]){
                dfs(j,i,adj,vis,cnt);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:connections){
            int a=it[0];
            int b=it[1];
            adj[a].push_back({b,1});
            adj[b].push_back({a,0});
        }
        vector<int>vis(n,0);
        int cnt=0;
        dfs(0,-1,adj,vis,cnt);
        return cnt;
    }
};