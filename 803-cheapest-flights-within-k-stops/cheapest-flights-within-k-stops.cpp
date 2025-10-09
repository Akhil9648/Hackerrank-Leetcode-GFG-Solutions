class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int,pair<int,int>>>q;
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights){
            int a=it[0];
            int b=it[1];
            int c=it[2];
            adj[a].push_back({b,c});
        }
        vector<int>dist(n,1e9);
        dist[src]=0;
        q.push({0,{src,0}});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int dis=it.second.second;
            if(stops>k) continue;
            for(auto it:adj[node]){
                int des=it.first;
                int cost=it.second;
                if(dis+cost<dist[des] && stops<=k){
                    dist[des]=dis+cost;
                    q.push({stops+1,{des,dist[des]}});
                }
            }
        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};