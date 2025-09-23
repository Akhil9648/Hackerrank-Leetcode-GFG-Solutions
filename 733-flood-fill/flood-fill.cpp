class Solution {
public:
    void bfs(int i,int j,vector<vector<int>>& grid,int ogcolor,int color){
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vis[i][j]=1;
        queue<pair<int,int>>q;
        q.push({i,j});
        int dr[4] = {-1, 0, 1, 0};
        int dc[4] = {0, 1, 0, -1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nr=r+dr[k];
                int nc=c+dc[k];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==ogcolor && !vis[nr][nc]){
                    vis[nr][nc]=1;
                    grid[nr][nc]=color;
                    q.push({nr,nc});
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]!=color){
            int c=image[sr][sc];
            image[sr][sc]=color;
            bfs(sr,sc,image,c,color);
        }
        return image;
    }
};