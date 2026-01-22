class Solution {
public:
int M=1e9+7;
    string states[12] = {"RYG", "RGY", "RYR", "RGR", "YRG", "YGR", "YGY", "YRY", "GRY", "GYR", "GRG", "GYG"};
    int solve(int n,int prev,vector<vector<int>>& dp){
        if(n==0) return 1;
        if(dp[n][prev]!=-1) return dp[n][prev];
        int result=0;
        string last=states[prev];
        for(int curr=0;curr<12;curr++){
            if(curr==prev) continue;
            bool got=false;
            string ths=states[curr];
            for(int i=0;i<3;i++){
                if(ths[i]==last[i]){
                    got=true;
                    break;
                }
            }
            if(!got){
                result=(result+solve(n-1,curr,dp))%M;
            }
        }
        return dp[n][prev]=result;
    }
    int numOfWays(int n) {
        int res=0;
        vector<vector<int>>dp(n+1,vector<int>(12,-1));
        for(int i=0;i<12;i++){
            res=(res+solve(n-1,i,dp))%M;
        }
        return res;
    }
};