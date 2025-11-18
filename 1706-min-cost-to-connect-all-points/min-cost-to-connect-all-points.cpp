class Solution {
public:
    int prims(int V,vector<vector<pair<int,int>>>& adj){
        int sum=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        vector<int>vis(V,0);
        while(!pq.empty()){
            auto tp=pq.top();
            pq.pop();
            int dis=tp.first;
            int node=tp.second;
            if(vis[node]) continue;
            vis[node]=true;
            sum+=dis;
            for(auto it:adj[node]){
                int cost=it.second;
                int a=it.first;
                if(!vis[a]){
                    pq.push({cost,a});
                }
            }
        }
        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V=points.size();
        vector<vector<pair<int,int>>>adj(V);
        for(int i=0;i<V;i++){
            for(int j=i+1;j<V;j++){
                int a=points[i][0];
                int b=points[i][1];
                int c=points[j][0];
                int d=points[j][1];
                int e=abs(a-c)+abs(b-d);
                adj[i].push_back({j,e});
                adj[j].push_back({i,e});
            }
        }
        return prims(V,adj);
    }
};