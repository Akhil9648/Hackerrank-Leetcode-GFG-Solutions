class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>st(nums.begin(),nums.end());
        for(int i=1;i<=nums.size()+1;i++){
            if(st.find(k*i)==st.end()) return k*i;
        }
        return -1;
    }
};