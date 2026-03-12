class Solution {
public:
    int solve(int i,vector<int>& nums,int n,vector<int>& dp){
        int take=1e5;
        if(i>=n) return 1e5;
        if(i==n-1) return 0;
        if(dp[i]!=-1) return dp[i];
        for(int j=1;j<=nums[i];j++){
            int curr=1+solve(i+j,nums,n,dp);
            take=min(take,curr);
        }
        return dp[i]=take;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(0,nums,n,dp);
    }
};