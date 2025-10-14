class Solution {
public:
    bool increase(int j,int k,vector<int>&nums){
        for(int i=j+1;i<j+k;i++){
            if(nums[i]<=nums[i-1]) return false;
        }
        return true;
    }
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        if (k == 1) return n >= 2;
        for(int i=0;i+2*k<=n;i++){
            if(increase(i,k,nums) && increase(i+k,k,nums)) return true;
        }
        return false;
    }
};