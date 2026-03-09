class Solution1 {
public:
    int l;
    int MOD=1e9+7;
    int solve(int zero,int one,int limit,int prev,vector<vector<vector<vector<int>>>>& dp){
        if(zero==0 && one==0) return 1;
        if(dp[zero][one][limit][prev+1]!=-1) return dp[zero][one][limit][prev+1];
        int take=0,notTake=0;
        if(prev==-1){
            if(zero>0) take=solve(zero-1,one,limit-1,0,dp);
            if(one>0) notTake=solve(zero,one-1,limit-1,1,dp);
            return dp[zero][one][limit][prev+1]=(take+notTake)%MOD;
        }
        if(prev==0){
            if(limit>0 && zero>0){
                take=solve(zero-1,one,limit-1,0,dp);
            }
            if(one>0) notTake=solve(zero,one-1,l-1,1,dp);
        }
        if(prev==1){
            if(limit>0 && one>0){
                take=solve(zero,one-1,limit-1,1,dp);
            }
            if(zero>0) notTake=solve(zero-1,one,l-1,0,dp);
        }
        return dp[zero][one][limit][prev+1]=(take+notTake)%MOD;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        l=limit;
        vector<vector<vector<vector<int>>>> dp(zero+1,vector<vector<vector<int>>>(one+1,vector<vector<int>>(limit+1,vector<int>(3, -1))));
        return solve(zero,one,limit,-1,dp);
    }
};
class Solution2 {
public:
    int MOD=1e9+7;
    int solve(int zero,int one,int limit,int prev,vector<vector<vector<int>>>& dp){
        if(zero==0 && one==0) return 1;
        if(dp[zero][one][prev]!=-1) return dp[zero][one][prev];
        int take=0,notTake=0;
        if(prev==0){
            for(int i=1;i<=min(limit,one);i++){
                take=(take+solve(zero,one-i,limit,1,dp))%MOD;
            }
            take%=MOD;
        }
        else{
            for(int i=1;i<=min(limit,zero);i++){
                take=(take+solve(zero-i,one,limit,0,dp))%MOD;
            }
        }
        take%=MOD;
        return dp[zero][one][prev]=(take)%MOD;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<int>>> dp(zero+1,vector<vector<int>>(one+1,vector<int>(2, -1)));
        int a=(solve(zero,one,limit,0,dp));
        int b=(solve(zero,one,limit,1,dp));
        return (a+b)%MOD;
    }
};
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