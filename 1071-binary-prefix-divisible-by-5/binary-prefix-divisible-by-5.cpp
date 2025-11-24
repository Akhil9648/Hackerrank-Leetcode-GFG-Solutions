class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool>ans;
        int a=0;
        for(int i:nums){
            a=(a*2+i)%5;
            ans.push_back(a%5==0);
        }
        return ans;
    }
};