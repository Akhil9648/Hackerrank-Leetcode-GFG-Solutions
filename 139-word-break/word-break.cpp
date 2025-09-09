class Solution {
public:
    bool solve(int i,string s,unordered_set<string>st,vector<int>& dp){
        if(i==s.size()) return true;
        if(dp[i]!=-1) return dp[i];
        for(int j=i;j<s.size();j++){
            string str=s.substr(i,j-i+1);
            if(st.find(str)!=st.end()){
                if(solve(j+1,s,st,dp)) return dp[i]=true;
            }
        }
        return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st;
        for(auto se:wordDict){
            st.insert(se);
        }
        vector<int>dp(s.size(),-1);
        return solve(0,s,st,dp);
    }
};