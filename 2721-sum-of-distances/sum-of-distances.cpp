class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        vector<long long>ans(n);
        for(auto &it:mp){
            vector<int>&idx=it.second;
            int k=idx.size();
            vector<long long>pref(k+1,0);
            for(int i=0;i<k;i++){
                pref[i+1]=pref[i]+idx[i];
            }
            for(int i=0;i<k;i++){
                long long left=(long long)idx[i]*i-pref[i];
                long long right=(pref[k]-pref[i+1])-(long long)idx[i]*(k-i-1);
                ans[idx[i]]=left+right;
            }
        }
        return ans;
    }
};