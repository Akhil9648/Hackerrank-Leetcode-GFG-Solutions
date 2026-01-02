class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        unordered_map<int,int>mp;
        int n=st.size();
        for(int i:nums){
            mp[i]++;
        }
        for(auto it:mp){
            if(it.second==(n-1)) return it.first;
        }
        return -1;
    }
};