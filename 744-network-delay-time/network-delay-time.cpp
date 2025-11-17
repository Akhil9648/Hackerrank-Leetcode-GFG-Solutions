class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>vis(n+1,0);
        pq.push({0,k});
        int visi=0;
        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            int dis=p.first;
            int node=p.second;
            if(vis[node]) continue;
            vis[node]=1;
            for(auto it:adj[node]){
                int a=it.first;
                int b=it.second;
                if(!vis[a]){
                    if(dis+b<dist[a]){
                        dist[a]=dis+b;
                        pq.push({dist[a],a});
                    }
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX) return -1;
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};