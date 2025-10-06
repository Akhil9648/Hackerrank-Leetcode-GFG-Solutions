// Approach-1 DFS
class Solution1 {
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
// Approach-2 BFS
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int v:graph[i]){
                adj[v].push_back(i);
            }
        }
        vector<int>indeg(n,0);
        for(int i=0;i<n;i++){
            for(int it:adj[i]){
                indeg[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0) q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int a=q.front();
            q.pop();
            ans.push_back(a);
            for(int i:adj[a]){
                indeg[i]--;
                if(indeg[i]==0) q.push(i);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};