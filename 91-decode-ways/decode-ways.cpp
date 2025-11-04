class Solution {
public:
    int n;
    int solve(int i,string s,vector<int>& dp){
        if(i==n) return 1;
        if(s[i]=='0') return 0;
        if(dp[i]!=-1) return dp[i];
        int oneTake=0,twoTake=0;
        if(i+1<n){
            int a=(s[i]-'0')*10+(s[i+1]-'0');
            if(a<=26 && a>=10){
                twoTake=solve(i+2,s,dp);
            }
        }
        oneTake=solve(i+1,s,dp);
        return dp[i]=oneTake+twoTake;
    }
    int numDecodings(string s) {
        n=s.size();
        vector<int>dp(n,-1);
        return solve(0,s,dp);
    }
};