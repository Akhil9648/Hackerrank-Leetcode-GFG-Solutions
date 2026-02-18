class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;
        int sum=0,mini=INT_MAX;
        while(j<n){
            sum+=nums[j];
            while(sum>=target){
                sum-=nums[i];
                mini=min(mini,j-i+1);
                i++;
            }
            j++;
        }
        return mini==INT_MAX?0:mini;
    }
};