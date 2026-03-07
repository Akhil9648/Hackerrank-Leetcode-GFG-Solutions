class Solution {
public:
int n;
    bool solve(int i,string &s,vector<string>& wordDict,vector<int>& dp){
        if(i>=n) return true;
        if(dp[i]!=-1) return dp[i];
        for(auto it:wordDict){
            if(i+it.size()>n) continue;
            int flag=0;
            for(int j=0;j<it.size();j++){
                if(it[j]!=s[i+j]){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                if(solve(i+it.size(),s,wordDict,dp)){
                    dp[i]=1;
                    return true;
                }
            }
        }
        dp[i]=0;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n=s.size();
        vector<int>dp(n,-1);
        return solve(0,s,wordDict,dp);
    }
};