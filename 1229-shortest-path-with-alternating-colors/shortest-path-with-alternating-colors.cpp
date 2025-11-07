class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>>red(n),blue(n);
        for(auto it:redEdges){
            red[it[0]].push_back(it[1]);
        }
        for(auto it:blueEdges){
            blue[it[0]].push_back(it[1]);
        }
        queue<pair<int,int>>q;
        q.push({0,0});
        q.push({0,1});
        vector<int>dist(n,INT_MAX);
        int level=0;
        vector<vector<int>>vis(n,vector<int>(2,0));
        while(!q.empty()){
            int size=q.size();
            while(size--){
            auto it=q.front();
            q.pop();
            int node=it.first;
            int col=it.second;
            if(vis[node][col]) continue;
            vis[node][col]=1;
            dist[node]=min(dist[node],level);
            if(col==0){
                for(auto it:blue[node]){
                    if(!vis[it][1]){
                        q.push({it,1});
                    }
                }
            }
            else{
                for(auto it:red[node]){
                    if(!vis[it][0]) q.push({it,0});
                }
            }
            }
            level++;
        }
        for(int i=0;i<n;i++){
            if(dist[i]==INT_MAX) dist[i]=-1;
        }
        return dist;
    }
};