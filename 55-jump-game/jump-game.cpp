class Solution1 {
public:
    int n;
    bool solve(int i,vector<int>& nums){
        if(i==n-1) return true;
        if(i>=n) return false;
        for(int j=1;j<=nums[i];j++){
            if(solve(i+j,nums)) return true;
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
        n=nums.size();
        return solve(0,nums);
    }
};
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            if(i>maxi) return false;
            maxi=max(maxi,nums[i]+i);
            if(maxi>=n-1) return true;
        }
        return true;
    }
};