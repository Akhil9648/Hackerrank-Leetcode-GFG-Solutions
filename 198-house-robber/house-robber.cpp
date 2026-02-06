class Solution {
public:
int n;
    int solve(int i,vector<int>& nums,vector<int>& dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int take=0,notTake=0;
        take=nums[i]+solve(i+2,nums,dp);
        notTake=solve(i+1,nums,dp);
        return dp[i]=max(take,notTake);
    }
    int rob(vector<int>& nums) {
        n=nums.size();
        vector<int>dp(n,-1);
        return solve(0,nums,dp);
    }
};