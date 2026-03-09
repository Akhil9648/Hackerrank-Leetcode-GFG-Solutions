class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        int MOD=1e9+7;
        vector<vector<vector<int>>> dp(zero+1,vector<vector<int>>(one+1,vector<int>(2, -1)));
        dp[0][0][1]=1;
        dp[0][0][0]=1;
        for(int i=0;i<=zero;i++){
            for(int j=0;j<=one;j++){
                if(i==0 && j==0) continue;
                int res=0;
                for(int k=1;k<=min(limit,i);k++){
                    res=(res+dp[i-k][j][0])%MOD;
                }
                dp[i][j][1]=res;
                res=0;
                for(int k=1;k<=min(limit,j);k++){
                    res=(res+dp[i][j-k][1])%MOD;
                }
                dp[i][j][0]=res;
            }
        }
        return (dp[zero][one][0]+dp[zero][one][1])%MOD;
    }
};