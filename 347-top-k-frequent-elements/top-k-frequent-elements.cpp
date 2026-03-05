class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int  n=nums.size();
        unordered_map<int,int>mp;
        for(int i:nums){
            mp[i]++;
        }
        int u=k;
        priority_queue<pair<int,int>>pq;
        vector<int>ans;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        while(k--){
            auto it=pq.top();
            pq.pop();
            ans.push_back(it.second);
        }
        return ans;
    }
};