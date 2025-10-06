class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int even=0,odd=0;
        int n=nums.size();
        for(int i=1;i<n;i+=2){
            odd+=nums[i];
        }
        for(int i=0;i<n;i+=2){
            even+=nums[i];
        }
        return even-odd;
    }
};