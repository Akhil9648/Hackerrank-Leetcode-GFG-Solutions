class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int i:arr) mp[i]++;
        unordered_set<int>st;
        for(auto it:mp){
            st.insert(it.second);
        }
        return st.size()==mp.size();
    }
};