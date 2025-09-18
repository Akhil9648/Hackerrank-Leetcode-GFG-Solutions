class Solution1 {
public:
    void solve(int i,vector<int>&nums,vector<int>& ans,vector<int>& curr){
        if(i==nums.size()){
            if(curr.size()>ans.size()){
                ans=curr;
            }
            return;
        }
        if(curr.size()==0){
            curr.push_back(nums[i]);
            solve(i+1,nums,ans,curr);
            curr.pop_back();
            solve(i+1,nums,ans,curr);
        }
        if(curr.size()>0){
            int a=curr.back();
            if(nums[i]%a==0 || a%nums[i]==0){
                curr.push_back(nums[i]);
                solve(i+1,nums,ans,curr);
                curr.pop_back();
            }
            solve(i+1,nums,ans,curr);
        }
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int>ans,curr;
        sort(begin(nums),end(nums));
        solve(0,nums,ans,curr);
        return ans;
    }
};
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n=nums.size();
        vector<int>dp(n,1),curr(n);
        int maxi=1,l=0;
        for(int i=0;i<n;i++){
            curr[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                    curr[i]=j;
                }
            }
        if(dp[i]>maxi){
            maxi=dp[i];
            l=i;
        }
        }
        vector<int>ans;
        ans.push_back(nums[l]);
        while(curr[l]!=l){
            l=curr[l];
            ans.push_back(nums[l]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};