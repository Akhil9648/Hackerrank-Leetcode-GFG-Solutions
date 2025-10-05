class Solution {
public:
    bool dfs(int i,vector<int>& vis,vector<int>& safe,vector<int>& check,vector<vector<int>>& graph){
        vis[i]=1;
        safe[i]=1;
        check[i]=0;
        for(int it:graph[i]){
            if(!vis[it]){
                if(dfs(it,vis,safe,check,graph)){
                    check[it]=0;
                    return true;
                }
            }
            if(safe[it]==1){
                check[it]=0;
                return true;
            }
        }
        check[i]=1;
        safe[i]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,0),safe(n,0),check(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,safe,check,graph);
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(check[i]) ans.push_back(i);
        }
        return ans;
    }
};