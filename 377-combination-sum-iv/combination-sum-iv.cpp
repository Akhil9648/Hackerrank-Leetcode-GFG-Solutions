class Solution1 {
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
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(target+1,0);
        dp[0]=1;
        for(int i=1;i<=target;i++){
        unsigned long long ans=0;
            for(int j:nums){
                if(j>i) break;
                ans+=dp[i-j];
            }
            dp[i]=ans;
        }
        return (int)dp[target];
    }
};