class Solution {
public:
    int n,m;
    int solve(int i,int j,vector<vector<int>>& dungeon,vector<vector<int>>& dp){
        if(i==n-1 && j==m-1){
            return dungeon[i][j]<0?abs(dungeon[i][j])+1:1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int taker=1e9,taked=1e9;
        if(i+1<n){
            taker=solve(i+1,j,dungeon,dp);
        }
        if(j+1<m){
            taked=solve(i,j+1,dungeon,dp);
        }
        int need=min(taked,taker)-dungeon[i][j];
        return dp[i][j]=need<=0?1:need;

    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        n=dungeon.size();
        m=dungeon[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(0,0,dungeon,dp);
    }
};