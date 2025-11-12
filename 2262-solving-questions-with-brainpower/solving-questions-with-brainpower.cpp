class Solution {
public:
    int n;
    long long solve(int i,vector<vector<int>>& questions,vector<long long>& dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        long long take=questions[i][0]+solve(i+questions[i][1]+1,questions,dp);
        long long notTake=solve(i+1,questions,dp);
        return dp[i]=max(take,notTake);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        n=questions.size();
        vector<long long>dp(1e5+1,-1);
        return solve(0,questions,dp);
    }
};