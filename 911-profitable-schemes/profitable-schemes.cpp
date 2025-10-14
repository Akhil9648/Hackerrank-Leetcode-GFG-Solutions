class Solution {
public:
int MOD=1e9+7;
    int solve(int i,int n,int mini,vector<int>& group,vector<int>& profit,int prof,vector<vector<vector<int>>>& dp){
        if(i==profit.size()){
            if(n>=0 && prof>=mini) return dp[i][n][prof]=1;
            return dp[i][n][prof]=0;
        }
        if(i>profit.size()) return 0;
        if(dp[i][n][prof]!=-1) return dp[i][n][prof];
        int take=0,nott=0;
        int nextProf = min(mini, prof + profit[i]);
        if((n-group[i])>=0) take=solve(i+1,n-group[i],mini,group,profit,nextProf,dp);
        nott=solve(i+1,n,mini,group,profit,prof,dp);
        return dp[i][n][prof]=(take+nott)%MOD;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int ans=0;
        int m=profit.size();
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(minProfit+1, -1)));
        ans=solve(0,n,minProfit,group,profit,0,dp);
        return ans;
    }
};