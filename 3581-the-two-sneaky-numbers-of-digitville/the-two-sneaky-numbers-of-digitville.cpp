class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_set<int>st;
        vector<int>ans;
        for(int i:nums){
            if(st.find(i)!=st.end()){
                ans.push_back(i);
            }
            st.insert(i);
        }
        return ans;
    }
};