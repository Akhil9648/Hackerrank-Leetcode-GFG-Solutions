class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n=rains.size();
        vector<int>ans(n,-1);
        unordered_map<int,int>mp;
        set<int>st;
        for(int i=0;i<n;i++){
            if(rains[i]>0){
                if(mp.count(rains[i])){
                    auto it=st.upper_bound(mp[rains[i]]);
                    if(it==st.end()) return {};
                    ans[*it]=rains[i];
                    st.erase(it);
                }
                mp[rains[i]]=i;
                ans[i]=-1;
            }
            else{
                st.insert(i);
                ans[i]=1;
            }
        }
        return ans;
    }
};