class Solution {
public:
    int mini=INT_MAX,maxi=INT_MIN;
    void binarysearch(int low,int high,vector<int>& nums,int target){
        if(low>high) return;
        int mid=low+(high-low)/2;
        if(nums[mid]==target){
            mini=min(mini,mid);
            maxi=max(maxi,mid);
            binarysearch(low,mid-1,nums,target);
            binarysearch(mid+1,high,nums,target);
        }
        else if(nums[mid]>target){
            binarysearch(low,mid-1,nums,target);
        }
        else binarysearch(mid+1,high,nums,target);
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        binarysearch(0,n-1,nums,target);
        if(mini==INT_MAX) return {-1,-1};
        return {mini,maxi};
    }
};