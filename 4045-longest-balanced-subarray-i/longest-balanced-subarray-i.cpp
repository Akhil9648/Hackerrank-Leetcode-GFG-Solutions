class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            int e=0,o=0;
            unordered_set<int>st;
            for(int j=i;j<n;j++){
                if(st.find(nums[j])==st.end()){
                if(nums[j]%2==0) e++;
                else o++;
                }
                if(e==o) maxi=max(maxi,j-i+1);
                st.insert(nums[j]);
            }
        }
        return maxi;
    }
};