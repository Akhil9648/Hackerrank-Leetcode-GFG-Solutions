class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>>vec;
        int n=nums1.size();
        for(int i=0;i<n;i++){
            vec.push_back({nums1[i],nums2[i]});
        }
        auto lambda=[&](auto &p1,auto &p2){
            return p1.second>p2.second;
        };
        sort(vec.begin(),vec.end(),lambda);
        long long sum=0;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<k;i++){
            sum+=vec[i].first;
            pq.push(vec[i].first);
        }
        long long result=1LL*sum*vec[k-1].second;
        for(int i=k;i<n;i++){
            sum-=pq.top();
            pq.pop();
            sum+=vec[i].first;
            pq.push(vec[i].first);
            result=max(result,1LL*sum*vec[i].second);
        }
        return result;
    }
};