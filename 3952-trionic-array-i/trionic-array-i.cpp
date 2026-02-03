class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(i<n-1 && nums[i]<nums[i+1]){
            i++;
        }
        if(i==0) return false;
        int peak=i;
        while(i<n-1 && nums[i]>nums[i+1]){
            i++;
        }
        if(i==peak || i==n-1) return false;
        int valley=i;
        while(i<n-1 && nums[i]<nums[i+1]) i++;
        return (i>valley && i==n-1);
        return false;
    }
};