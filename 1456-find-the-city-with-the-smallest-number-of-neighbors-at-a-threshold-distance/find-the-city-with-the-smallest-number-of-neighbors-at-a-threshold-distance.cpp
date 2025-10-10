class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int mini=INT_MAX,city=-1;
        vector<vector<int>>adj(n,vector<int>(n,INT_MAX));
        for(auto it:edges){
            int a=it[0];
            int b=it[1];
            int c=it[2];
            adj[a][b]=c;
            adj[b][a]=c;
        }
        for(int i=0;i<n;i++) adj[i][i]=0;
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(adj[i][k]==INT_MAX || adj[k][j]==INT_MAX) continue;
                    adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
                }
            }
        }
        for(int i=0;i<n;i++){
            int a=0;
            for(int j=0;j<n;j++){
                if(adj[i][j]<=distanceThreshold) a++;
            }
            if(a<=mini){
                mini=a;
                city=i;
            }
        }
        return city;
    }
};