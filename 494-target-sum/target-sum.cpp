class Solution {
public:
    int n;
    void solve(int i,vector<int>& nums,int target,int &cnt){
        if(i>=n){
            if(target==0) cnt++;
            return;
        }
        solve(i+1,nums,target-nums[i],cnt);
        solve(i+1,nums,target+nums[i],cnt);
        return ;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        n=nums.size();
        int cnt=0;
        solve(0,nums,target,cnt);
        return cnt;
    }
};