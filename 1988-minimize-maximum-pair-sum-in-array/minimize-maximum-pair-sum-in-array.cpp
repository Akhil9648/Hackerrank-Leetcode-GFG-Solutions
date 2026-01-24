class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int j=nums.size()-1;
        int maxi=0;
        sort(nums.begin(),nums.end());
        int i=0;
        while(i<j){
            maxi=max(maxi,nums[i]+nums[j]);
            i++;
            j--;
        }
        return maxi;
    }
};