class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        int ans=0;
        int dr[]={0,1,0,-1};
        int dc[]={1,0,-1,0};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    q.push({i,j});
                    vis[i][j]=1;
                    int size=1;
                    while(!q.empty()){
                        auto top=q.front();
                        q.pop();
                        int r=top.first;
                        int c=top.second;
                        for(int k=0;k<4;k++){
                            int nr=r+dr[k];
                            int nc=c+dc[k];
                            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && !vis[nr][nc]){
                                size++;
                                vis[nr][nc]=1;
                                q.push({nr,nc});
                            }
                        }
                    }
                    ans=max(ans,size);
                }
            }
        }
        return ans;
    }
};