class Solution {
public:
    void solve(int i,vector<int>&nums,vector<vector<int>>&ans,vector<int>&curr,int k){
        if(k==0){
            ans.push_back(curr);
            return;
        }
        if(k<0) return;
        for(int j=i;j<nums.size();j++){
            if(k-nums[j]>=0){
                curr.push_back(nums[j]);
                solve(j,nums,ans,curr,k-nums[j]);
                curr.pop_back();
            }
        }
        return ;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>curr;
        solve(0,candidates,ans,curr,target);
        return ans;
    }
};