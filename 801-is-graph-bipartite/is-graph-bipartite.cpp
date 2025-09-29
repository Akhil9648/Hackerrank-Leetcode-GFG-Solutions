class Solution1 {
public:
    bool check(int i,int n,vector<vector<int>>& graph,vector<int>& color){
        queue<int>q;
        q.push(i);
        color[i]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int it:graph[node]){
                if(color[it]==-1){
                    color[it]=!color[node];
                    q.push(it);
                }
                else if(color[it]==color[node]) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!check(i,n,graph,color)) return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    bool dfs(int i,int col,vector<int>&color,vector<vector<int>>& graph){
        color[i]=col;
        for(auto it:graph[i]){
            if(color[it]==-1){
                if(!dfs(it,!col,color,graph)) return false;
            }
            else if(color[it]==col) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!dfs(i,0,color,graph)) return false;
            }
        }
        return true;
    }
};