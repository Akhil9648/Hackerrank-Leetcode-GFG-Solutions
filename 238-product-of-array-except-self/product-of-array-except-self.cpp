class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>pre(n,1),post(n,1);
        int mul=1;
        for(int i=0;i<n;i++){
            pre[i]=mul;
            mul*=nums[i];
        }
        mul=1;
        for(int i=n-1;i>=0;i--){
            post[i]=mul;
            mul*=nums[i];
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=pre[i]*post[i];
        }
        return ans;
    }
};