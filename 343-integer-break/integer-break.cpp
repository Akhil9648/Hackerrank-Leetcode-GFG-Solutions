class Solution {
public:
    int solve(int n,vector<int>& dp){
        if(n==1) return 1;
        if(n<=0) return 0;
        if(dp[n]!=-1) return dp[n];
        int maxi=0;
        for(int i=1;i<=n;i++){
            maxi=max(maxi,max(i*solve(n-i,dp),i*(n-i)));
        }
        return dp[n]=maxi;
    }
    int integerBreak(int n) {
        vector<int>dp(n+1,-1);
       return solve(n,dp); 
    }
};