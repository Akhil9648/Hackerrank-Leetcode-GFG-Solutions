class Solution {
public:
int n;
    int count(string s){
        int n=s.size();
        int i=0;
        int cnt=0;
        while(i<n/2){
            if(s[i]!=s[n-i-1]) cnt++;
            i++;
    }
        return cnt;
    }
    int solve(int i,string & s,int k,vector<vector<int>>& dp){
        int n=s.size();
        if(i>=n) return 1e9;
        if(k==1){
            string left=s.substr(i);
            return count(left);
        }
        if(dp[i][k]!=-1) return dp[i][k];
        int ans=INT_MAX;
        for(int j=i;j<n;j++){
            string a;
            for(int u=i;u<=j;u++) a.push_back(s[u]);
            int t=count(a);
            t+=solve(j+1,s,k-1,dp);
            ans=min(ans,t);
            if(ans==0) return dp[i][k]=0;
        }
        return dp[i][k]=ans;
    }
    int palindromePartition(string s, int k) {
        int n=s.size();
        if(k>=s.size()) return 0;
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return solve(0,s,k,dp);
    }
};