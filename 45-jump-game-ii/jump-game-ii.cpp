class Solution1 {
public:
    int solve(int i,vector<int>& nums,int len,vector<int>&dp){
        if(i>=nums.size()-1) return len;
        if(dp[i]!=-1) return dp[i];
        int mini=INT_MAX;
        for(int j=1;j<=nums[i];j++){
            mini=min(mini,solve(j+i,nums,len+1,dp));
        }
        return dp[i]=mini;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(0,nums,0,dp);
    }
};
class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0,ans=0;
        while(r<n-1){
            int maxi=0;
            for(int i=l;i<=r;i++){
                maxi=max(maxi,i+nums[i]);
            }
            l=r+1;
            r=maxi;
            ans+=1;
        }
        return ans;
    }
};