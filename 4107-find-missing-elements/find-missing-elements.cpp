class Solution1 {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int a=nums[0];
        int b=nums[n-1];
        vector<int>ans;
        unordered_set<int>st(nums.begin(),nums.end());
        for(int i=a;i<b;i++){
            if(st.find(i)==st.end()) ans.push_back(i);
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int a=*min_element(nums.begin(),nums.end());
        int b=*max_element(nums.begin(),nums.end());
        vector<int>ans;
        unordered_set<int>st(nums.begin(),nums.end());
        for(int i=a;i<b;i++){
            if(st.find(i)==st.end()) ans.push_back(i);
        }
        return ans;
    }
};