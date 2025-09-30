class Solution {
public:
    int triangularSum(vector<int>& nums) {
        while(nums.size()>1){
            int n=nums.size();
            vector<int>arr;
            for(int i=1;i<n;i++){
                int a=(nums[i-1]+nums[i])%10;
                arr.push_back(a);
            }
            nums=arr;
        }
        return nums[0];
    }
};