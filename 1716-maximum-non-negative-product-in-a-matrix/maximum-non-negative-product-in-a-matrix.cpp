class Solution {
public:
    int n,m;
    typedef long long ll;
    int mod=1e9+7;
    pair<ll,ll>solve(int i,int j,vector<vector<int>>&grid,vector<vector<pair<ll,ll>>>&dp){
       if(i==n-1 && j==m-1) return {grid[i][j],grid[i][j]};
       if(dp[i][j]!=make_pair(LLONG_MIN, LLONG_MAX)) return dp[i][j];
       ll maxv=LLONG_MIN;
        ll minv=LLONG_MAX;
        if(i+1<n){
        auto [dmax,dmin]=solve(i+1,j,grid,dp);
        maxv=max({maxv,grid[i][j]*dmax,grid[i][j]*dmin});
        minv=min({minv,grid[i][j]*dmax,grid[i][j]*dmin});
        }
        if(j+1<m){
            auto [rmax,rmin]=solve(i,j+1,grid,dp);
            maxv=max({maxv,grid[i][j]*rmax,grid[i][j]*rmin});
            minv=min({minv,grid[i][j]*rmax,grid[i][j]*rmin});
        }
        return dp[i][j]={maxv,minv};
    }
    int maxProductPath(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<pair<ll,ll>>>dp(n,vector<pair<ll,ll>>(m,{LLONG_MIN, LLONG_MAX}));
        auto [a,b]=solve(0,0,grid,dp);
        return a<0?-1:a%mod;
    }
};