class Solution {
public:
    int n;
    void solve(vector<int>& curr,vector<int>& nums,vector<vector<int>>& ans){
        if(curr.size()>=n){
            ans.push_back(curr);
            return;
        }
        for(int j=0;j<n;j++){
            if(nums[j]<=10){
                curr.push_back(nums[j]);
                int a=nums[j];
                nums[j]=11;
                solve(curr,nums,ans);
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
        solve(curr,nums,ans);
        return ans;
    }
};