class Solution {
public:
    int getdig(int n){
        int ans=0;
        while(n){
            if(n%2==0){
                break;
            }
            ans++;
            n/=2;
        }
        return ans;
    }
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                ans.push_back(-1); 
                continue;
            }
            int a=getdig(nums[i]);
            int res=nums[i]-pow(2,a-1);
            ans.push_back(res);
        }
        return ans;
    }
};