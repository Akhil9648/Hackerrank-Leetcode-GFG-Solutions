class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:times){
            int a=it[0];
            int b=it[1];
            int c=it[2];
            adj[a].push_back({b,c});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        vector<int>dist(n+1,1e9);
        dist[k]=0;
        while(!pq.empty()){
            auto ed=pq.top();
            pq.pop();
            int dis=ed.first;
            int node=ed.second;
            for(auto it:adj[node]){
                int wt=it.second;
                int adj=it.first;
                if(dis+wt<dist[adj]){
                    dist[adj]=dis+wt;
                    pq.push({dist[adj],adj});
                }
            }
        }
        int ans=-1;
        for(int i=1;i<=n;i++){
            if(dist[i]==1e9) return -1;
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};