class Solution {
public:
    int numWaterBottles(int n, int k) {
        int ans=n;
        while(n>=k){
            if(n%k==0){
                n/=k;
                ans+=n;
            }
            else{
                int a=n%k;
                n/=k;
                ans+=n;
                n+=a;
            }
        }
        return ans;
    }
};