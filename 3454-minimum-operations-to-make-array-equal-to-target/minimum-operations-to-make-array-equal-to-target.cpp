class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n=nums.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            ans[i]=(target[i]-nums[i]);
        }
        long long ops=(ans[0]<0)?0:ans[0];
        for(int i=1;i<n;i++){
            if(ans[i]>ans[i-1]){
                ops+=(ans[i]-ans[i-1]);
            }
        }
        if(ans[n-1]<0) ops+=abs(ans[n-1]);
        return ops;
    }
};