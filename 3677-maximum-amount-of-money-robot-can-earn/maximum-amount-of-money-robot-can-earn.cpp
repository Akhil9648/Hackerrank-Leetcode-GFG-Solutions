class Solution {
public:
    int n,m;
    int solve(int i,int j,vector<vector<int>>& coins,int nuet,vector<vector<vector<int>>>& dp){
        if(i==n-1 && j==m-1){
            if(coins[i][j]<0 && nuet>0) return 0;
            return coins[i][j];
        }
        if(i>=n || j>=m) return -1e9;
        if(dp[i][j][nuet]!=INT_MIN) return dp[i][j][nuet];
        int right=0,bottom=0,rightnuet=-1e9,bottomnuet=-1e9;
        if(coins[i][j]<0 && nuet>0){
            if(i<n) rightnuet=solve(i+1,j,coins,nuet-1,dp);
            if(j<m) bottomnuet=solve(i,j+1,coins,nuet-1,dp);
        }
        if(i<n) right=coins[i][j]+solve(i+1,j,coins,nuet,dp);
        if(j<m) bottom=coins[i][j]+solve(i,j+1,coins,nuet,dp);
        return dp[i][j][nuet]=max({right,bottom,rightnuet,bottomnuet});
    }
    int maximumAmount(vector<vector<int>>& coins) {
        n=coins.size();
        m=coins[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(3,INT_MIN)));
        return solve(0,0,coins,2,dp);
    }
};
