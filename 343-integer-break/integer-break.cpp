class Solution1 {
public:
    int solve(int n,vector<int>& dp){
        if(n==1) return 1;
        if(n<=0) return 0;
        if(dp[n]!=-1) return dp[n];
        int maxi=0;
        for(int i=1;i<=n;i++){
            maxi=max(maxi,max(i*solve(n-i,dp),i*(n-i)));
        }
        return dp[n]=maxi;
    }
    int integerBreak(int n) {
        vector<int>dp(n+1,-1);
       return solve(n,dp); 
    }
};
class Solution {
public:
    int integerBreak(int n) {
        vector<int>dp(n+1,-1);
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++){
                dp[i]=max(dp[i],max((j*dp[i-j]),(j*(i-j))));
            }
        }
        return dp[n];
    }
};