class Solution1 {
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
class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=i-1;j>=-1;j--){
                int len=dp[i+1][j+1];
                if(j==-1 || nums[i]>nums[j]){
                    len=max(len,1+dp[i+1][i+1]);
                }
            dp[i][j+1]=len;
            }

        }
    return dp[0][0];
    }
};
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,1);
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};