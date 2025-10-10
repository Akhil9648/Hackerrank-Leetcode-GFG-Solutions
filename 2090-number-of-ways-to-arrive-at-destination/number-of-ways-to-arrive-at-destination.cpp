class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:roads){
            int a=it[0];
            int b=it[1];
            int c=it[2];
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long>dist(n,LLONG_MAX);
        vector<int>ways(n,0);
        dist[0]=0;
        ways[0]=1;
            int mod=1e9+7;
        pq.push({0,0});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            long long dis=it.first;
            int node=it.second;
            if (dis > dist[node]) continue;
            for(auto i:adj[node]){
                int wt=i.second;
                int j=i.first;
                if((dis+wt)==dist[j]){
                    ways[j]=(ways[j]+ways[node])%mod;
                }
                else if((dis+wt)<dist[j]){
                    ways[j]=ways[node];
                    dist[j]=dis+wt;
                    pq.push({dist[j],j});
                }
            }
        }
        return ways[n-1]%mod;
    }
};