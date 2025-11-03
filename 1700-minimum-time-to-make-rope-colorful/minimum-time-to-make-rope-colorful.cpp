class Solution1 {
public:
int n;
    int solve(int i,string colors,vector<int>& time,int prev,vector<vector<int>>& dp){
        if(i==n) return 0;
        int p=prev+1;
        if(dp[i][p]!=-1) return dp[i][p];
        if(prev==-1 || colors[i]!=colors[i-1]){
            return dp[i][p]=solve(i+1,colors,time,i,dp);
        }
        else{
            int takecurr=time[i]+solve(i+1,colors,time,prev,dp);
            int takeprev=time[prev]+solve(i+1,colors,time,i,dp);
            return dp[i][p]=min(takecurr,takeprev);
        }
    }
    int minCost(string colors, vector<int>& neededTime) {
        n=colors.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(0,colors,neededTime,-1,dp);
    }
};
class Solution {
public:
    int minCost(string colors, vector<int>& time) {
        int n=colors.size();
        int ans=0;
        for(int i=1;i<n;i++){
            if(colors[i]==colors[i-1]){
                ans+=min(time[i],time[i-1]);
                time[i]=max(time[i],time[i-1]);
            }
        }
        return ans;
    }
};