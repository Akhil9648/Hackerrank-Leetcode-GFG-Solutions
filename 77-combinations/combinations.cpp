class Solution {
public:
    void solve(int i,int n,int k,vector<vector<int>>& ans,vector<int> nums){
        if(nums.size()==k){
            ans.push_back(nums);
            return;
        }
        for(int j=i;j<=n;j++){
            nums.push_back(j);
            solve(j+1,n,k,ans,nums);
            nums.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>arr;
        solve(1,n,k,ans,arr);
        return ans;
    }
};