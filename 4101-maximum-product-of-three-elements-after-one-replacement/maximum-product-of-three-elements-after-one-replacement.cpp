class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end(),[](int a,int b){
            if(abs(a)==abs(b)){
                return a<b;
            }
            return abs(a)<abs(b);
        });
        int mini=INT_MAX,flag=0;
        long long mul=1;
        for(int i=n-3;i<n;i++){
            mini=min(mini,abs(nums[i]));
            if(nums[i]==0){
                if(!flag){
                    flag=1;
                    continue;
                }
                else return 0;
            }
            mul*=abs(nums[i]);
        }
        if(mini!=0) mul/=mini;
        mul*=1e5;
        return mul;
    }
};