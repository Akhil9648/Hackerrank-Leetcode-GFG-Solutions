class Solution {
public:
    bool solve(int i,vector<int>& nums,int n,vector<int>& dp){
        if(i>=n-1) return true;
        if(dp[i]!=-1) return dp[i]==1?true:false;
        for(int j=1;j<=nums[i];j++){
            if(solve(i+j,nums,n,dp)){
                dp[i]=1;
                return true;
            }
        }
        dp[i]=0;
        return false;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return true;
        vector<int>dp(n,-1);
        return solve(0,nums,n,dp);
    }
};