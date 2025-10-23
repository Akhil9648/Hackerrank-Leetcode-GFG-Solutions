class Solution {
public:
    int n;
    int solve(int i,vector<int>& cost,vector<int>& dp){
        if(i>=n) return 0;
        if(i==n-1) return cost[i];
        if(dp[i]!=-1) return dp[i];
        int one=cost[i]+solve(i+1,cost,dp);
        int two=cost[i]+solve(i+2,cost,dp);
        return dp[i]=min(one,two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        n=cost.size();
        vector<int>dp(n+1,-1);
        int a=solve(0,cost,dp);
        int b=solve(1,cost,dp);
        return min(a,b);
    }
};