class Solution1 {
public:
    int solve(int i,int n,int k,vector<int>& arr,vector<int>& dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int sum=0,maxi=INT_MIN,len=0;
        for(int j=i;j<min(n,i+k);j++){
            maxi=max(maxi,arr[j]);
            sum=max(sum,(j-i+1)*maxi+solve(j+1,n,k,arr,dp));
        }
        return dp[i]=sum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n+1,-1);
        return solve(0,n,k,arr,dp);
    }
};
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
        int maxi=0;
            for(int j=i;j<min(n,i+k);j++){
                maxi=max(maxi,arr[j]);
                dp[i]=max(dp[i],(j-i+1)*maxi+dp[j+1]);
            }
        }
        return dp[0];
    }
};