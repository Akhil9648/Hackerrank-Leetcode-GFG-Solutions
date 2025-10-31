class Solution {
public:
    int n,m;
    int solve(int i,int j,string& s1,string& s2,vector<vector<int>>& dp){
        if(i>=n && j>=m) return 0; 
        if(i>=n){
            return s2[j]+solve(i,j+1,s1,s2,dp);
        }
        if(j>=m){
            int a=0;
            return s1[i]+solve(i+1,j,s1,s2,dp);
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j]=solve(i+1,j+1,s1,s2,dp);
        }
        int take=0,notTake=0;
            take=s1[i]+solve(i+1,j,s1,s2,dp);
            notTake=s2[j]+solve(i,j+1,s1,s2,dp);
        return dp[i][j]=min(take,notTake);
    }
    int minimumDeleteSum(string s1, string s2) {
        n=s1.size();
        m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(0,0,s1,s2,dp);
    }
};