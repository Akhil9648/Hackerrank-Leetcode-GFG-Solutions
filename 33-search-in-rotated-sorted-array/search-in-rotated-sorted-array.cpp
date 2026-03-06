class Solution1 {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int mini=INT_MAX,maxi=INT_MIN;
        int minind=0,maxind=0;
        for(int i=0;i<2*n;i++){
            if(nums[i%n]<mini){
                mini=nums[i%n];
                minind=i;
            }
            if(nums[i%n]>=maxi){
                maxi=nums[i%n];
                maxind=i;
            }
        }
        int ans=0;
        int low=minind,high=maxind;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid%n]==target){
                return mid%n;
            }
            else  if(nums[mid%n]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return -1;
    }
};
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int ans=0;
        int low=0,high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[low]<=nums[mid]){
                if(target>=nums[low] && target<=nums[mid]) high=mid-1;
                else low=mid+1;
            }
            else{
                if(target<nums[low] && target>nums[mid]){
                    low=mid+1;
                }
                else high=mid-1;
            }
        }
        return -1;
    }
};