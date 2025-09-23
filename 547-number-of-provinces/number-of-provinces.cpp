class Solution {
public:
    void dfs(int i,vector<int>&vis,vector<vector<int>>& isConnected){
        vis[i]=1;
        for(int it:isConnected[i]){
            if(!vis[it]){
                dfs(it,vis,isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size(),count=0;
        vector<int>vis(n+1,0);
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                dfs(i,vis,adj);
            }
        }
        return count;
    }
};