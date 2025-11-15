class Solution1 {
public:
    int n,m;
    void bfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis,
             int& size) {
        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = 1;
        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            int r = top.first;
            int c = top.second;
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    grid[nr][nc] == 1 && !vis[nr][nc]) {
                    size++;
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    int size = 1;
                    bfs(i, j, grid, vis, size);
                    ans = max(ans, size);
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    int n,m;
    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis,int & size){
        vis[i][j]=1;
        int dr[] = {0, 1, 0, -1};
        int dc[] = {1, 0, -1, 0};
        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && !vis[nr][nc]){
                size++;
                dfs(nr,nc,grid,vis,size);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    int size=1;
                    dfs(i,j,grid,vis,size);
                    ans = max(ans, size);
                }
            }
        }
        return ans;
    }
};