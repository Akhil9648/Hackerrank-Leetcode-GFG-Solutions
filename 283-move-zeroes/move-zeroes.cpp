class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int cnt0=0;
        for(int i:nums) if(i==0) cnt0++;
        int j=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                nums[j]=nums[i];
                j++;
            }
        }
        while(j<n){
            nums[j]=0;
            j++;
        }
    }
};