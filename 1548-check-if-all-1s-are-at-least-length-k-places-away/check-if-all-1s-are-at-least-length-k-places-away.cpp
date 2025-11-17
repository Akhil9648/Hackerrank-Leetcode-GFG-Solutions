class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int prev=1e9;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                if(abs(i-prev-1)<k) return false;
                prev=i;
            }
        }
        return true;
    }
};