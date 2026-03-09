class Solution {
public:
    vector<int>dr={0,1,0,-1};
    vector<int>dc={1,0,-1,0};
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            auto it=q.front();
            int r=it.first;
            int c=it.second;
            q.pop();
            for(int k=0;k<4;k++){
                int nr=r+dr[k];
                int nc=c+dc[k];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && !vis[nr][nc]){
                    q.push({nr,nc});
                    vis[nr][nc]=vis[r][c]+1;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    return -1;
                }
                ans=max(ans,vis[i][j]);
            }
        }
        return ans;
    }
};
