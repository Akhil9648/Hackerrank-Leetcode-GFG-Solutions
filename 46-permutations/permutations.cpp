class Solution {
public:
    int n;
    void solve(int i,vector<int>& curr,vector<int>& nums,vector<vector<int>>& ans){
        if(i>=n){
            ans.push_back(curr);
            return;
        }
        for(int j=0;j<n;j++){
            if(nums[j]<=10){
                curr.push_back(nums[j]);
                int a=nums[j];
                nums[j]=11;
                solve(i+1,curr,nums,ans);
                nums[j]=a;
                curr.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        vector<vector<int>> ans;
        vector<int>curr;
        solve(0,curr,nums,ans);
        return ans;
    }
};