class Solution {
public:
    int extractdig(int n,int digit){
        int cnt=0;
        while(n){
            if(n%10==digit) cnt++;
            n/=10;
        }
        return cnt;
    }
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int ans=0;
        for(auto it:nums){
            ans+=extractdig(it,digit);
        }
        return ans;
    }
};