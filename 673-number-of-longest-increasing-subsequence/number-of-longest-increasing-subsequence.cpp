class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1),cnt(n,1);
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if (nums[i] > nums[j]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j]; // reset count
                    } else if (dp[j] + 1 == dp[i]) {
                        cnt[i] += cnt[j]; // add ways
                    }
                }
            }
            maxi=max(maxi,dp[i]);
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi){
                count+=cnt[i];
            }
        }
        return count;
    }
};