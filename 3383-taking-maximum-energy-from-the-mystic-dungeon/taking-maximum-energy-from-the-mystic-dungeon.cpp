// Approach-1 Brute Force Approach Trying Basic recurtion and trying all combinations
// Failed TC-522
class Solution1 {
public:
    int solve(int i,vector<int>& energy,int k){
        int n=energy.size();
        if(i==n) return INT_MIN;
        int maxi=INT_MIN;
        int sum=0;
        for(int j=i;j<n;j+=k){
            sum+=energy[j];
        }
        int b=solve(i+1,energy,k);
        return max(sum,b);
    }
    int maximumEnergy(vector<int>& energy, int k) {
        return solve(0,energy,k);
    }
};
// Approach-2 Doing DFS on all the possibillities and finding the maximum possiblity among all
// TC-O(N*K)
class Solution2 {
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
// Optimal Approach Using Tabulation
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size();
        vector<int>dp(n,0);
        for(int i=n-1;i>=0;i--){
            dp[i]=energy[i];
            if(i+k<n) dp[i]+=dp[i+k];
        }
        return *max_element(dp.begin(),dp.end());
    }
};