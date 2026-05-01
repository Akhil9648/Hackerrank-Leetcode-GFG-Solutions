class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
       int n=nums.size();
        int ans=INT_MIN;
        int curr=0;
        int sum=0;
        for(int i=0;i<n;i++){
            curr+=(i*nums[i]);
            sum+=nums[i];
        }
        ans=max(ans,curr);
        int k=n-1;
        for(int i=0;i<n;i++){
            curr=curr+sum-(n*nums[k]);
            k--;
            ans=max(ans,curr);
        }
        return ans;
    }
};