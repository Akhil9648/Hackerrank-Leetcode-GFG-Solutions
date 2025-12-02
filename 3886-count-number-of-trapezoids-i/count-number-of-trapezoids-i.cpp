class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int MOD=1e9+7;
        int ans=0;
        unordered_map<int,int>mp;
        int n=points.size();
        for(int i=0;i<n;i++){
            mp[points[i][1]]++;
        }
        int prev=0;
        if(mp.size()<2) return 0;
        for(auto it:mp){
            long long a=it.second;
            long long u=(a*(a-1))/2;
            ans+=((1LL*u*prev)%MOD);
            ans%=MOD;
            prev=(prev+u)%MOD;
        }
        return ans;
    }
};