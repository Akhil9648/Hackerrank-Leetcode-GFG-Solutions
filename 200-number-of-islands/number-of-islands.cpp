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
    int numIslands(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    dfs(i,j,vis,grid);
                    count++;
                }
            }
        } 
        return count;
    }
};