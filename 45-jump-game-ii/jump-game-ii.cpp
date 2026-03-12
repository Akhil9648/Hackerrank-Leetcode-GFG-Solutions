class Solution1 {
public:
    int solve(int i,vector<int>& nums,int n,vector<int>& dp){
        int take=1e5;
        if(i>=n) return 1e5;
        if(i==n-1) return 0;
        if(dp[i]!=-1) return dp[i];
        for(int j=1;j<=nums[i];j++){
            int curr=1+solve(i+j,nums,n,dp);
            take=min(take,curr);
        }
        return dp[i]=take;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(0,nums,n,dp);
    }
};
class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0,cnt=0;
        while(r<n-1){
            int farthest=0;
            for(int i=l;i<=r;i++){
                farthest=max(farthest,i+nums[i]);
            }
            l=r+1;
            r=farthest;
            cnt++;
        }
        return cnt;
    }
};