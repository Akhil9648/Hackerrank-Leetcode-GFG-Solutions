class Solution1 {
public:
    int solve(int i,int j,vector<int>& arr,vector<vector<int>>& dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=1e9;
        for(int k=i;k<=j;k++){
            int ans=(arr[j+1]-arr[i-1])+solve(i,k-1,arr,dp)+solve(k+1,j,arr,dp);
            mini=min(mini,ans);
        }
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(c+2,vector<int>(c+1,-1));
        return solve(1,c,cuts,dp);
    }
};
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>>dp(c+2,vector<int>(c+2,0));
        for(int i=c;i>0;i--){
            for(int j=1;j<=c;j++){
                if(i>j) continue;
               int mini=1e9;
        for(int k=i;k<=j;k++){
            int ans=(cuts[j+1]-cuts[i-1])+dp[i][k-1]+dp[k+1][j];
            mini=min(mini,ans);
        }
        dp[i][j]=mini;
            }
        }
        return dp[1][c];
    }
};