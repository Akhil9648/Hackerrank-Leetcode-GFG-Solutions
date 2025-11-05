// Greedy but not correct for this problem
class Solution1 {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b){
            if (a[1] == b[1]) return a[0] > b[0];
             return a[1] < b[1];
        });
        int count=0,ans=0;
        int prev=-1;
        for(int i=0;i<pairs.size();i++){
            if(pairs[i][0]>prev){
                prev=pairs[i][1];
                ans++;
            }
        }
        return ans;
    }
};
class Solution {
public:
    int n;
    int solve(int i,int prev,vector<vector<int>>& pairs,vector<vector<int>>& dp){
        if(i==n) return 0;
        int take=0,notTake=0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        if(prev==-1 || pairs[prev][1]<pairs[i][0]){
            take=1+solve(i+1,i,pairs,dp);
        }
        notTake=solve(i+1,prev,pairs,dp);
        return dp[i][prev+1]=max(take,notTake);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        n=pairs.size();
        sort(pairs.begin(),pairs.end());
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(0,-1,pairs,dp);
    }
};