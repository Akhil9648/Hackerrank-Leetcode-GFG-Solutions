class Solution {
public:
    int size;
    pair<int,int> count(string s){
        int one=0;
        int zero=0;
        for(auto c:s){
            if(c=='0') zero++;
            else one++;
        }
        return {zero,one};
    }
    int solve(int i,vector<string>& str,int m,int n,vector<vector<vector<int>>>& dp){
        if(i>=size) return 0;
        if(m==0 && n==0) return 0;
        if(dp[i][m][n]!=-1) return dp[i][m][n];
        auto c=count(str[i]);
        int take=0,notTake=0;
        if(c.first<=m && c.second<=n){
            take=1+solve(i+1,str,m-c.first,n-c.second,dp);
        }  
        notTake=solve(i+1,str,m,n,dp);
        return dp[i][m][n]=max(take,notTake);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        size=strs.size();
        vector<vector<vector<int>>>dp(size,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return solve(0,strs,m,n,dp);
    }
};