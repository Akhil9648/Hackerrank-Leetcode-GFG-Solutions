class Solution {
public:
    int n;
    int find(int low,int high,vector<int>& nums){
        if(low==high) return low;
        int mid=(low+high)/2;
        if(nums[mid+1]>=nums[mid]){
            return find(mid+1,high,nums);
        }
        return find(low,mid,nums);
    }
    int findPeakElement(vector<int>& nums) {
        n=nums.size();
        int a=find(0,n-1,nums);
        return a;
    }
};