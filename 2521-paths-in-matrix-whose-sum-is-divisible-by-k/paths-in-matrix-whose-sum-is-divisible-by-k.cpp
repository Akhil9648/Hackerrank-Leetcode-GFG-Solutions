class Solution {
public:
    int MOD=1e9+7;
    int m,n;
    int solve(int i,int j,vector<vector<int>>& grid,int k,int sum,vector<vector<vector<int>>>& dp){
        if(i==m-1 && j==n-1){
            sum+=grid[i][j];
            if(sum%k==0) return dp[i][j][sum%k]=1;
            else return dp[i][j][sum%k]=0;
        }
        if(i>=m || j>=n) return 0;
        if(dp[i][j][sum%k]!=-1) return dp[i][j][sum%k];
        int right=solve(i+1,j,grid,k,sum+grid[i][j],dp);
        int down=solve(i,j+1,grid,k,sum+grid[i][j],dp);
        return dp[i][j][sum%k]=(right+down)%MOD;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m=grid.size();
        n=grid[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(k,-1)));
        return solve(0,0,grid,k,0,dp);
    }
};