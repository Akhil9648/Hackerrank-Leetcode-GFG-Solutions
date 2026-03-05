class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;
        dist[0]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int wt=it.first;
            int a=it.second;
            if(wt > dist[a]) continue;
            for(auto &i:adj[a]){
                int des=i.first;
                int w1=i.second;
                if(dist[des]>wt+w1){
                    dist[des]=wt+w1;
                    pq.push({wt+w1,des});
                }
            }
        }
        int maxi=0;
        for(int i:dist){
            maxi=max(maxi,i);
        }
        return maxi==INT_MAX?-1:maxi;
    }
};