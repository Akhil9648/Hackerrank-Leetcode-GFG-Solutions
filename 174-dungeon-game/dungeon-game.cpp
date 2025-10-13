class Solution1 {
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
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size();
        int m=dungeon[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 && j==m-1){
                    dp[i][j]=dungeon[i][j]<0?abs(dungeon[n-1][m-1])+1:1;
                }
                else{
                int down=(i+1>=n)?1e9:dp[i+1][j];
                int right=(j+1>=m)?1e9:dp[i][j+1];
                int need=min(down,right)-dungeon[i][j];
                dp[i][j]=(need<=0)?1:need; 
                }
            }
        }
        return dp[0][0];
    }
};