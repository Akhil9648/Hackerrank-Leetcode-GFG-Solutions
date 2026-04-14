class Solution {
public:
    void extractdig(int n,unordered_map<int,int>& mp){
        while(n){
            int d=n%10;
            mp[d]++;
            n/=10;
        }
    }
    int countDigitOccurrences(vector<int>& nums, int digit) {
        unordered_map<int,int>mp;
        for(auto it:nums){
            extractdig(it,mp);
        }
        return mp[digit];
    }
};