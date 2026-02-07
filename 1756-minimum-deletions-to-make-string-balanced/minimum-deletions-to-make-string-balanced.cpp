class Solution {
public:
int n;
    int solve(int i,int j,string &s,vector<vector<int>>& dp){
        if(i>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int res=1e9;
        if(j==0){
            if(s[i]=='a'){
                res=min(solve(i+1,0,s,dp),1+solve(i+1,0,s,dp));
            }
            else{
                res=min(1+solve(i+1,0,s,dp),solve(i+1,1,s,dp));
            }
        }
        else{
            if(s[i]=='a'){
                res=1+solve(i+1,1,s,dp);
            }
            else{
                res=solve(i+1,1,s,dp);
            }
        }
        return dp[i][j]=res;
    }
    int minimumDeletions(string s) {
        n=s.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,0,s,dp);
    }
};