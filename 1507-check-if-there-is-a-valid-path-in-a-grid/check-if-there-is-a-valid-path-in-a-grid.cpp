class Solution {
public:
    int n, m;
    
    vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    
    vector<vector<int>> street = {
        {},
        {0,1},           
        {2,3},              
        {1,2},          
        {0,2},           
        {1,3},              
        {0,3}               
    };
    
    bool dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        if(i == n-1 && j == m-1) return true;
        
        vis[i][j] = 1;
        
        for(int d : street[grid[i][j]]) {
            int ni = i + dirs[d][0];
            int nj = j + dirs[d][1];
            
            if(ni>=0 && ni<n && nj>=0 && nj<m && !vis[ni][nj]) {
                
                int rev = d ^ 1;
                
                for(int nd : street[grid[ni][nj]]) {
                    if(nd == rev) {
                        if(dfs(ni, nj, grid, vis)) return true;
                    }
                }
            }
        }
        return false;
    }
    
    bool hasValidPath(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        return dfs(0, 0, grid, vis);
    }
};