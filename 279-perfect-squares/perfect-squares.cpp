class Solution {
public:
    int solve(int i,int n,vector<int>& dp){
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        int ans=1e9;
        for(int j=i;j*j<=n;j++){
            int sq=j*j;
            int count=1+solve(j,n-sq,dp);
            ans=min(ans,count);
        }
        return dp[n]=ans;
    }
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return solve(1,n,dp);
    }
};