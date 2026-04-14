class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int ans=0;
        for(auto it:nums){
            while(it){
                if(it%10==digit) ans++;
                    it/=10;
            }
        }
        return ans;
    }
};