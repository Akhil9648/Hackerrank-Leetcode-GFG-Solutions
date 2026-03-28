class Solution {
public:
    int timer=0;
    void dfs(int i,vector<vector<int>>& adj,vector<int>& vis,int par,vector<int>& low,vector<int>& tin,vector<vector<int>>& ans){
        vis[i]=1;
        low[i]=tin[i]=timer;
        timer++;
        for(auto it:adj[i]){
            if(it==par) continue;
            if(!vis[it]){
                dfs(it,adj,vis,i,low,tin,ans);
                low[i]=min(low[i],low[it]);
                if(low[it]>tin[i]){
                    ans.push_back({i,it});
                }
            }
            else{
                low[i]=min(low[i],tin[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>vis(n,0),low(n,0),tin(n,0);
        vector<vector<int>>adj(n);
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<vector<int>>ans;
        dfs(0,adj,vis,-1,low,tin,ans);
        return ans;
    }
};