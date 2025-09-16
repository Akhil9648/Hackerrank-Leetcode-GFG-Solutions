class Solution {
public:
    int solve(int i,vector<int>&nums,int prev,vector<vector<int>>& dp){
        if(i==nums.size()){
            return 0;
        }
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int len=solve(i+1,nums,prev,dp);
        if(prev==-1 || nums[i]>nums[prev]){
            len=max(len,1+solve(i+1,nums,i,dp));
        } 
        dp[i][prev+1]=len;
        return len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(0,nums,-1,dp);
    }
};