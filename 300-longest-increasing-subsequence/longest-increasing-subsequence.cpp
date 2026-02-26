class Solution1 {
public:
    int n;
    int solve(int i,int prev,vector<int>& nums,vector<vector<int>>& dp){
        if(i>=n) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int take=0;
        if(prev==-1 || nums[i]>nums[prev]){
            take=1+solve(i+1,i,nums,dp);
        }
        int notTake=solve(i+1,prev,nums,dp);
        return dp[i][prev+1]=max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(0,-1,nums,dp);
    }
};
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>temp;
        for(int num:nums){
            auto it=lower_bound(temp.begin(),temp.end(),num);
            if(it==temp.end()) temp.push_back(num);
            else *it=num;
        }
        return temp.size();
    }
};