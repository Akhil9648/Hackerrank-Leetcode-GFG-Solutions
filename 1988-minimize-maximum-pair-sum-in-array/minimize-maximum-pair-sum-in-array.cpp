class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        sort(nums.begin(),nums.end());
        int i=0,j=n-1;
        while(i<j){
            maxi=max(maxi,nums[i]+nums[j]);
            i++;
            j--;
        }
        return maxi;
    }
};