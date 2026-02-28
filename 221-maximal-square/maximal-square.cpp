class Solution {
public:
int m,n;
    int solve(int i,int j,vector<vector<char>>& matrix,vector<vector<int>>& dp){
        if(i>=n || j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int take=0;
        if(matrix[i][j]=='1'){
            int right=solve(i,j+1,matrix,dp);
            int bottom=solve(i+1,j,matrix,dp);
            int diag=solve(i+1,j+1,matrix,dp);
            take=min(right,min(bottom,diag));
            return dp[i][j]=1+take;
        }
        return dp[i][j]=0;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        int maxi=0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1') 
                {
                    maxi=max(solve(i,j,matrix,dp),maxi);
                }
            }
        }
        return maxi*maxi;
    }
};