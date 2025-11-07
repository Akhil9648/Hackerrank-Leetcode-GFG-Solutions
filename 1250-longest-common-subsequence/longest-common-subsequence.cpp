class Solution1 {
public:
    int solve(string text1,string text2,int i,int j,vector<vector<int>>& dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int take=0;
        if(text1[i]==text2[j]){
            take=1+solve(text1,text2,i-1,j-1,dp);
        }
        int notTake=max(solve(text1,text2,i-1,j,dp),solve(text1,text2,i,j-1,dp));
        return dp[i][j]=max(take,notTake);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(text1,text2,n-1,m-1,dp);
    }
};
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        if(text1[0]==text2[0]) dp[0][0]=1;
        for(int j = 1; j < m; j++) {
            if(text1[0] == text2[j]) dp[0][j] = 1;
            else dp[0][j] = dp[0][j-1];
        }

        // Initialise first column
        for(int i = 1; i < n; i++) {
            if(text1[i] == text2[0]) dp[i][0] = 1;
            else dp[i][0] = dp[i-1][0];
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(text1[i]==text2[j]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n-1][m-1];
    }
};