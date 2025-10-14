class Solution {
public:
    int n,m;
    int solve(int i,int j,vector<int>& nums1, vector<int>& nums2,vector<vector<int>>& dp){
        if(i>=n || j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(nums1[i]==nums2[j]){
            return dp[i][j]=1+solve(i+1,j+1,nums1,nums2,dp);
        }
        int fix_i=solve(i,j+1,nums1,nums2,dp);
        int fix_j=solve(i+1,j,nums1,nums2,dp);
        return dp[i][j]=max(fix_i,fix_j);
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        n=nums1.size();
        m=nums2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(0,0,nums1,nums2,dp);
    }
};