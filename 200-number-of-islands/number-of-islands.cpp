class Solution {
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