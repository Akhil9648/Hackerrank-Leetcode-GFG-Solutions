class Solution {
public:
    int m,n,maxi=0;
    int solve(int i,int j,vector<vector<char>>& nums,vector<vector<int>>& dp){
        if(i>=m || j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int u=solve(i+1,j,nums,dp);
        int v=solve(i,j+1,nums,dp);
        int w=solve(i+1,j+1,nums,dp);
        int curr=0;
        if(nums[i][j]=='1'){
            curr=1+min({u,v,w});
            maxi=max(maxi,curr);
        }
        return dp[i][j]=curr;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        m=matrix.size();
        n=matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        solve(0,0,matrix,dp);
        return maxi*maxi;
    }
};