class Solution1 {
public:
int MOD=1e9+7;
    int solve(int n,int delay,int forget,vector<int>& dp){
        if(n==1) return 1;
        int result=0;
        if(dp[n]!=-1) return dp[n];
        for(int i=n-forget+1;i<=n-delay;i++){
            if(i>0){
            result+=solve(i,delay,forget,dp);
            result%=MOD;
            }
        }
        return dp[n]=result;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int total=0;
        vector<int>dp(n+1,-1);
        for(int i=n-forget+1;i<=n;i++){
            if(i>0){
                total+=solve(i,delay,forget,dp);
                total%=MOD;
            }
        }
        return total;
    }
};
class Solution {
public:
int MOD=1e9+7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int total=0;
        vector<int>dp(n+1,-1);
        dp[1]=1;
    for(int j=2;j<=n;j++){
        long long count=0;
        for(int i=j-forget+1;i<=j-delay;i++){
            if(i>0){
            count+=dp[i];
            count%=MOD;
            }
        }
        dp[j]=count;
    }
    int result=0;
    for(int i=n-forget+1;i<=n;i++){
        result+=dp[i];
        result%=MOD;
    }
        return result;
    }
};