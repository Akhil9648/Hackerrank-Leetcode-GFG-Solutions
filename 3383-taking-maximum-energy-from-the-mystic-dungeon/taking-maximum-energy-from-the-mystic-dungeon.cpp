class Solution {
public:
    int solve(int i,vector<int>& energy,int k,vector<int>& dp){
        int n=energy.size();
        if(i>=n) return 0;
        if(dp[i]!=INT_MIN) return dp[i];
        int maxi=INT_MIN;
        int sum=energy[i];
        if(i+k<n){
            sum+=solve(i+k,energy,k,dp);
        }
        return dp[i]=sum;
    }
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size();
        vector<int>dp(n,INT_MIN);
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            ans=max(ans,solve(i,energy,k,dp));
        }
        return ans;
    }
};