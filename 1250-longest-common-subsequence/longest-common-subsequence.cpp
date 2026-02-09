class Solution {
public:
int n,m;
    int solve(int i,int j,string& text1,string& text2,vector<vector<int>>& dp){
        if(i>=n || j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int take=0,take1=0,take2=0;
        if(text1[i]==text2[j]){
            take=1+solve(i+1,j+1,text1,text2,dp);
            return dp[i][j]=take;
        }
        else{
            take1=solve(i+1,j,text1,text2,dp);
            take2=solve(i,j+1,text1,text2,dp);
            return dp[i][j]=max(take1,take2);
        }
        return -1;
    }
    int longestCommonSubsequence(string text1, string text2) {
        n=text1.size();
        m=text2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(0,0,text1,text2,dp);
    }
};