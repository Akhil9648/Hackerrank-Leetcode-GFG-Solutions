class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(i+k<=n){
            priority_queue<pair<int,int>,vector<pair<int,int>>>pq;
            unordered_map<int,int>mp;
            for(int j=i;j<i+k;j++){
                mp[nums[j]]++;
            }
            for(auto it:mp){
                pq.push({it.second,it.first});
            }
            int u=x;
            int sum=0;
            while(!pq.empty() && u--){
                auto it=pq.top();
                sum+=(it.first*it.second);
                pq.pop();
            }
            ans.push_back(sum);
            }
        }
        return ans;
    }
};