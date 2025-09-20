class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        
        // Precompute palindromes
        for(int i = n-1; i >= 0; i--) {
            for(int j = i; j < n; j++) {
                if(s[i] == s[j] && (j - i < 2 || isPal[i+1][j-1])){
                    isPal[i][j] = true;
                }
            }
        }
        
        vector<int> dp(n+1, 0);
        dp[0] = -1; // base case, no cuts needed before start
        
        for(int i = 1; i <= n; i++){
            dp[i] = INT_MAX;
            for(int j = 0; j < i; j++){
                if(isPal[j][i-1]){
                    dp[i] = min(dp[i], 1 + dp[j]);
                }
            }
        }
        
        return dp[n];
    }
};
