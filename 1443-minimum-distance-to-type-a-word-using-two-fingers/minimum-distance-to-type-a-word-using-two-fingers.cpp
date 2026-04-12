class Solution {
public:
    int n;
    int dist(int a, int b, string &s) {
    if (a == 26) return 0;
    int r1 = a / 6;
    int c1 = a % 6;
    int r2 = (s[b] - 'A') / 6;
    int c2 = (s[b] - 'A') % 6;
    return abs(r1 - r2) + abs(c1 - c2);
}
    int solve(int i,int f1,int f2,string &s,vector<vector<vector<int>>>& dp){
        if(i>=n) return 0;
        if(dp[i][f1][f2]!=-1) return dp[i][f1][f2];
        int a=dist(f1,i,s)+solve(i+1,s[i]-'A',f2,s,dp);
        int b=dist(f2,i,s)+solve(i+1,f1,s[i]-'A',s,dp);
        return dp[i][f1][f2]=min(a,b);
    }
    int minimumDistance(string word) {
        n=word.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(27,vector<int>(27,-1)));
        return solve(0,26,26,word,dp);
    }
};