class Solution {
public:
    int solve(int n,vector<int>& dp){
        if(n==0) return 0;
        if(n<3) return 1;
        if(dp[n]!=-1) return dp[n];
        int ans=solve(n-3,dp)+solve(n-2,dp)+solve(n-1,dp);
        return dp[n]=ans; 
    }
    int tribonacci(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};