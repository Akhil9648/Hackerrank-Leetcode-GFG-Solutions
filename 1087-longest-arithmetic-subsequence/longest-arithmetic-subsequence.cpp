// Apprach-1 Basic Idea 29/65 Passed
class Solution1 {
public:
int n;
    int solve(int i,vector<int>& nums,int diff,int prev,vector<unordered_map<int,int>>& dp){
        if(i>=n) return 0;
        int take=0,notTake=0;
        if(dp[i].count(diff)) return dp[i][diff];
        if((nums[i]-prev)==diff){
            take=1+solve(i+1,nums,diff,nums[i],dp);
        }
        notTake=solve(i+1,nums,diff,prev,dp);
        return dp[i][diff]=max(take,notTake);
    }
    int longestArithSeqLength(vector<int>& nums) {
        n=nums.size();
        int maxi=0;
        int u=*max_element(nums.begin(),nums.end());
        vector<unordered_map<int,int>>dp(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                maxi=max(maxi,2+solve(j+1,nums,nums[j]-nums[i],nums[j],dp));
            }
        }
        return maxi;
    }
};
// Apprach-2 Tabulation
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>dp[n];
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int diff=nums[i]-nums[j];
                int len=dp[j].count(diff)?dp[j][diff]+1:2;
                dp[i][diff]=max(dp[i][diff],len);
                maxi=max(maxi,dp[i][diff]);   
            }
        }
        return maxi;
    }
};