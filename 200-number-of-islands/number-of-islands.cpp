class Solution1 {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        int count = 0;
        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    count++;
                    q.push({i, j});
                    vis[i][j] = 1;
                    while (!q.empty()) {
                        int flag = 1;
                        auto top = q.front();
                        q.pop();
                        int r = top.first;
                        int c = top.second;
                        for (int i = 0; i < 4; i++) {
                            int nr = r + dr[i];
                            int nc = c + dc[i];
                            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                                !vis[nr][nc] && grid[nr][nc] == '1') {
                                q.push({nr, nc});
                                vis[nr][nc] = 1;
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};
class Solution {
public:
    int n,m;
    void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>>& vis){
        vis[i][j]=1;
        int dr[]={0,1,0,-1};
        int dc[]={1,0,-1,0};
        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]=='1' && !vis[nr][nc]){
                dfs(nr,nc,grid,vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int count=0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    dfs(i,j,grid,vis);
                    count++;
                }
            }
        }
        return count;
    }
};