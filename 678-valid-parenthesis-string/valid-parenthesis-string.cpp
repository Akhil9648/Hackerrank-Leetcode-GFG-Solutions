class Solution {
public:
    bool solve(int i,string s,int count,vector<vector<int>>& dp){
        if(count<0) return false;
        if(i==s.size()) return count==0;
        if(dp[i][count]!=-1) return dp[i][count];
        if(s[i]=='(') return dp[i][count]=solve(i+1,s,count+1,dp);
        if(s[i]==')') return dp[i][count]=solve(i+1,s,count-1,dp);
        return dp[i][count]=solve(i+1,s,count+1,dp) || solve(i+1,s,count-1,dp) || solve(i+1,s,count,dp);
    }
    bool checkValidString(string s) {
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,-1));
        return solve(0,s,0,dp);
    }
};