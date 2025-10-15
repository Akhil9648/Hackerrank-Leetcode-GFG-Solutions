class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int pre=0,curr=1,k=0;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                curr++;
            }
            else{
                pre=curr;
                curr=1;
            }
            k=max(k,(curr/2));
            k=max(k,min(pre,curr));
        }
        return k;
    }
};