class Solution {
public:
    bool dfs(int i,vector<vector<int>>& adj,vector<int>& vis){
        vis[i]=-1;
        for(int node:adj[i]){
            if(vis[node]==-1) return false;
            if(vis[node]==0){
                if(!dfs(node,adj,vis)){
                    vis[node]=-1;
                    return false;
                }
            }
        }
        vis[i]=1;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(vis[i]==-1 || !dfs(i,adj,vis)) return false;
        }
        return true;
    }
};