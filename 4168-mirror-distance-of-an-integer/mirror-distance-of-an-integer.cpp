class Solution {
public:
    int reverse(int n){
        int ans=0;
        while(n){
            int d=n%10;
            ans*=10;
            ans+=d;
            n/=10;
        }
        return ans;
    }
    int mirrorDistance(int n) {
        int a=reverse(n);
        return abs(n-a);
    }
};