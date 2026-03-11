class Solution {
public:
    int n;
    int solve(int i,vector<int>& nums,int prev,vector<vector<int>>& dp){
        if(i>=n) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int take=0,notTake=0;
        if(prev==-1){
            take=1+solve(i+1,nums,i,dp);
        }
        else if(nums[prev]<nums[i]){
            take=1+solve(i+1,nums,i,dp);
        }
        notTake=solve(i+1,nums,prev,dp);
        return dp[i][prev+1]=max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(0,nums,-1,dp);
    }
};
class Solution1 {
public:
    int n;
    int solve(int i,vector<int>& nums,int prev,vector<vector<int>>& dp){
        if(i>=n) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int take=0,notTake=0;
        if(prev==-1){
            take=1+solve(i+1,nums,i,dp);
        }
        else if(nums[prev]<nums[i]){
            take=1+solve(i+1,nums,i,dp);
        }
        notTake=solve(i+1,nums,prev,dp);
        return dp[i][prev+1]=max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(0,nums,-1,dp);
    }
};