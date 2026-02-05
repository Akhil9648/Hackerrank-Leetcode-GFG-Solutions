class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>result(n);
        for(int i=0;i<n;i++){
            int j=nums[i];
            int u=i;
            if(nums[i]<0){
                u=i-abs(j);
                while(u<0){
                    u+=n;
                }
                u%=n;
            }
            else if(nums[i]>0){
                u=(i+j)%n;
            }
            result[i]=nums[u];
        }
        return result;
    }
};