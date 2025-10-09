class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        dist[0][0]=1;
        q.push({1,{0,0}});
        int dr[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dc[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
        while(!q.empty()){
            auto it=q.front();
            int dis=it.first;
            int a=it.second.first;
            int b=it.second.second;
            if(a==n-1 && b==n-1) return dist[a][b];
            q.pop();
            for(int i=0;i<8;i++){
                int nr=a+dr[i];
                int nc=b+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==0 && dis+1<dist[nr][nc]){
                    dist[nr][nc]=1+dis;
                    q.push({dist[nr][nc],{nr,nc}});
                }
            }
        }
        return -1;
    }
};