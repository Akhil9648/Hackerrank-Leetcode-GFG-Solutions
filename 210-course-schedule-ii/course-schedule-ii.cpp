class Solution {
public:
    bool solve(int i,vector<vector<int>>& adj,vector<int>&vis,vector<int>& ans,vector<int>&pathvis){
        vis[i]=1;
        pathvis[i]=1;
        for(auto it:adj[i]){
            if(!vis[it]){
                if(solve(it,adj,vis,ans,pathvis)) return true;
            }
            else if(pathvis[it]) return true;
        }
        pathvis[i]=0;
        ans.push_back(i);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(numCourses,0),ans,pathvis(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(solve(i,adj,vis,ans,pathvis)) return {};
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};