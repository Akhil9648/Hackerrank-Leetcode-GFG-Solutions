class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int mini=INT_MAX;
        int n=nums.size();
        for(int i=0;i+k-1<n;i++){
            mini=min(mini,nums[i+k-1]-nums[i]);
        }
        return mini==INT_MAX?0:mini;
    }
};