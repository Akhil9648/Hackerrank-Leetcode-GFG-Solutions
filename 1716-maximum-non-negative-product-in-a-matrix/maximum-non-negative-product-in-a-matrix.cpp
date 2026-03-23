class Solution {
public:
    typedef long long ll;
    int MOD=1e9+7;
    pair<ll,ll> solve(int i,int j,vector<vector<int>>& grid,vector<vector<pair<ll,ll>>>& dp){
        if(i==0 && j==0) return {grid[i][j],grid[i][j]};
        if(i<0 || j<0) return {1e9,-1e9};
        if(dp[i][j] != make_pair(LLONG_MAX, LLONG_MIN)) return dp[i][j];
        ll mini=LLONG_MAX;
        ll maxi=LLONG_MIN;
        if(i-1>=0){
            pair<ll,ll> up=solve(i-1,j,grid,dp);
            mini=min(mini,min(grid[i][j]*up.first,grid[i][j]*up.second));
            maxi=max(maxi,max(grid[i][j]*up.first,grid[i][j]*up.second));
        }
        if(j-1>=0){
            pair<ll,ll> left=solve(i,j-1,grid,dp);
            maxi=max(maxi,max(grid[i][j]*left.first,grid[i][j]*left.second));
            mini=min(mini,min(grid[i][j]*left.first,grid[i][j]*left.second));
        }
        return dp[i][j]={mini,maxi};
    }
    int maxProductPath(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<pair<ll,ll>>>dp(n,vector<pair<ll,ll>>(m,{LLONG_MAX,LLONG_MIN}));
        pair<ll,ll> a=solve(n-1,m-1,grid,dp);
        auto maxi=a.second;
        return maxi<0?-1:maxi%MOD;
    }
};