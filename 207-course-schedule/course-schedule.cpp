class Solution {
public:
    bool dfs(int i,vector<vector<int>>& adj,vector<int>& vis,vector<int>& path){
        vis[i]=1;
        path[i]=1;
        for(auto it:adj[i]){
            if(!vis[it]){
                if(dfs(it,adj,vis,path)) return true;
            }
            else if(path[it]) return true;
        }
        path[i]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto it:prerequisites){
            adj[it[0]].push_back(it[1]);
        }
        vector<int>vis(numCourses,0),path(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,path)) return false;
            }
        }
        return true;
    }
};