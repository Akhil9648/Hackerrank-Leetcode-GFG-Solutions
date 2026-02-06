class Solution {
public:
    int n,m;
        vector<int>dr={0,1,0,-1};
        vector<int>dc={1,0,-1,0};
    void dfs(int i,int j,vector<vector<int>>& vis,vector<vector<char>>& grid){
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int r=i+dr[k];
            int c=j+dc[k];
            if(r>=0 && r<n && c>=0 && c<m && grid[r][c]=='1' && !vis[r][c]){
                dfs(r,c,vis,grid);
            }
        }
    }
    void bfs(int i,int j,vector<vector<int>>& vis,vector<vector<char>>& grid){
    vis[i][j]=1;
    queue<pair<int,int>>q;
    q.push({i,j});
        while(!q.empty()){
            auto it=q.front();
            int r=it.first;
            int c=it.second;
            q.pop();
            for(int k=0;k<4;k++){
                int nr=r+dr[k];
                int nc=c+dc[k];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]=='1' && !vis[nr][nc]){
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    bfs(i,j,vis,grid);
                    count++;
                }
            }
        } 
        return count;
    }
};