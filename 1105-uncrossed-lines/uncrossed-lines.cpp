class Solution {
public:
    int solve(vector<int>& nums1,vector<int>& nums2,int i,int j,vector<vector<int>>& dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int take=0;
        if(nums1[i]==nums2[j]){
            take=1+solve(nums1,nums2,i-1,j-1,dp);
        }
        int notTake=max(solve(nums1,nums2,i-1,j,dp),solve(nums1,nums2,i,j-1,dp));
        return dp[i][j]=max(take,notTake);
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(nums1,nums2,n-1,m-1,dp);
    }
};