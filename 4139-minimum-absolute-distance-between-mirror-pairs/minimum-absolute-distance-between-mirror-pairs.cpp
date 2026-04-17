class Solution {
public:
    int reverse(int x){
        long long ans=0;
        while(x){
            int d=x%10;
            ans*=10;
            ans+=d;
            x/=10;
        }
        return (int)ans;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int ans=INT_MAX;
        for(int i=n-1;i>=0;i--){
            int a=reverse(nums[i]);
            if(mp.count(a)){
                int dis=mp[a]-i;
                ans=min(ans,dis);
            }
            mp[nums[i]]=i;
        }
        return ans==INT_MAX?-1:ans;
    }
};