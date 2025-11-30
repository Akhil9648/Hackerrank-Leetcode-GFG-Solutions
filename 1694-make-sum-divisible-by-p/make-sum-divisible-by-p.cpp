class Solution1 {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        vector<long long>pref(n,0);
        pref[0]=nums[0];
        for(int i=1;i<n;i++){
            pref[i]=nums[i]+pref[i-1];
        }
        long long sum=pref[n-1];
        if(sum%p==0) return 0;
        int to_remove=sum%p;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                long long current_sub_sum = pref[j] - ((i > 0) ? pref[i-1] : 0);
                if(current_sub_sum%p==to_remove){
                    mini=min(mini,(j-i+1));
                }
            }
        }
        if(mini==n) return -1;
        return (mini==INT_MAX)?-1:mini;
    }
};
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n=nums.size();
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%p==0) return 0;
        int target=sum%p;
        int mini=INT_MAX;
        unordered_map<int,int>mp;
        mp[0]=-1;
        long long currsum=0;
        for(int i=0;i<n;i++){
            currsum+=nums[i];
            int currmod=currsum%p;
            int req=(currmod-target+p)%p;
            if(mp.count(req)){
                mini=min(mini,(i-mp[req]));
            }
            mp[currmod]=i;
        }
        if(mini==n) return -1;
        return (mini==INT_MAX)?-1:mini;
    }
};