class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            int sum=0;
            unordered_set<int>st;
            for(int k=i;k>=0;k--){
                st.insert(nums[k]);
                sum+=nums[k];
                if(st.find(sum)!=st.end()) count++;
            }
        }
        return count;
    }
};