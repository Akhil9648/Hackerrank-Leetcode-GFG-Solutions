class Solution {
public:
    vector<int>dr={0,1,0,-1};
    vector<int>dc={1,0,-1,0};
    int n,m;
    int dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i>=n || j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]>grid[i][j]){
                ans=max(ans,1+dfs(nr,nc,grid,dp));
            }
        }
        return dp[i][j]=ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m=matrix[0].size();
        n=matrix.size();
        int ans=0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,1+dfs(i,j,matrix,dp));
            }
        }
        return ans;
    }
};