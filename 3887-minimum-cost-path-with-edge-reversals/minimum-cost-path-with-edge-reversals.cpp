class Solution1 {
public:
    void dfs(int i,vector<vector<pair<int,int>>>& adj,int &mini,int cost,vector<int>& vis,int n){
        vis[i]=1;
        if(i==n-1){
            mini=min(mini,cost);
        }
        for(auto it:adj[i]){
            int node=it.first;
            int weight=it.second;
            if(!vis[node]){
                dfs(node,adj,mini,cost+weight,vis,n);
                vis[node]=0;
            }
        }
    }
    int minCost(int n, vector<vector<int>>& edges) {
        vector<int>vis(n,0);
        int m=edges.size();
        vector<vector<pair<int, int>>>adj(n+1);
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],2*it[2]});
        }
        int mini=INT_MAX;
        dfs(0,adj,mini,0,vis,n);
        return mini==INT_MAX?-1:mini;
    }
};
class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        // vector<int>vis(n,0);
        int m=edges.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<vector<pair<int, int>>>adj(n+1);
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],2*it[2]});
        }
        pq.push({0,0});
        vector<int>dist(n+1,INT_MAX);
        int mini=INT_MAX;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int d=it.first;
            int node=it.second;
            if(d>dist[node]) continue;
            if(node==n-1){
                return d;
            }
            for(auto i:adj[node]){
                int weight=i.second;
                int ni=i.first;
                if(d+weight<dist[ni]){
                    dist[ni]=d+weight;
                    pq.push({d+weight,ni});
                    // vis[ni]=1;
                }
            }
        }
        return -1;
    }
};