class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        int maxi=0;
        for(int i:nums){
            mp[i]++;
            maxi=max(maxi,mp[i]);
        }
        int sum=0;
        for(auto it:mp){
            if(it.second==maxi) sum+=maxi;
        }
        return sum;
    }
};