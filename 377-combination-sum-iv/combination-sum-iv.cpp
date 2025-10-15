class Solution {
public:
    int n;
    int solve(vector<int>& nums,int target,vector<int>&dp){
        if(target==0) return 1;
        if(dp[target]!=-1) return dp[target];
        int count=0;
        for(int i=0;i<n;i++){
            if(target-nums[i]>=0){
                count+=solve(nums,target-nums[i],dp);
            }
            else{
                break;
            }
        }
        return dp[target]=count;
    }
    int combinationSum4(vector<int>& nums, int target) {
        n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(target+1,-1);
        return solve(nums,target,dp);
    }
};