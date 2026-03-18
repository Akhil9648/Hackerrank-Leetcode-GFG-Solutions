class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr=0,maxi=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            curr+=nums[i];
            maxi=max(maxi,curr);
            if(curr<0){
                curr=0;
            }
        }
        return maxi==INT_MIN?0:maxi;
    }
};