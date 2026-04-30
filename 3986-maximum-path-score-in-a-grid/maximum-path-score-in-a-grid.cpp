class Solution {
public:
    int n,m;
    int solve(int i,int j,vector<vector<int>>&grid,int k,vector<vector<vector<int>>>& dp){
        if(i>=n || j>=m || k<0) return -1e9;
        if(i == n-1 && j == m-1){
            if(grid[i][j]>0) k--;
            if(k >= 0) return grid[i][j];
            return -1e9;
        }
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        int a=k;
        int takeb=0,taker=0;
        if(grid[i][j]>0) a--;
        takeb=solve(i+1,j,grid,a,dp);
        taker=solve(i,j+1,grid,a,dp);
        return dp[i][j][k]=grid[i][j]+max(taker,takeb);
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        int a=solve(0,0,grid,k,dp);
        return a<0?-1:a;
    }
};