class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int mini=INT_MAX;
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        queue<pair<int,pair<int,int>>>pq;
        pq.push({0,{src,k}});
        vector<int>dist(n,1e9);
        dist[src]=0;
        while(!pq.empty()){
            auto it=pq.front();
            int pr=it.first;
            int node=it.second.first;
            int k0=it.second.second;
            pq.pop();
            if(k0<0) continue;
            for(auto it:adj[node]){
                int p0=it.second;
                int d=it.first;
                if(dist[d]>pr+p0){
                    dist[d]=pr+p0;
                    pq.push({dist[d],{d,k0-1}});
                }
            }
        }
        return dist[dst]==1e9?-1:dist[dst];
    }
};