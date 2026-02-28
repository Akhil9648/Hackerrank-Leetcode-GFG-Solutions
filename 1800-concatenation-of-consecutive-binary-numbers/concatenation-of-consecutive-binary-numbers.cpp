class Solution {
public:
    int MOD=1e9+7;
    long long power = 1;
    int bit = 0;
    int add(int n){
        long long sum=0;
        while(n){
            int d=n%2;
            if (d == 1) {
                sum = (sum + power) % MOD;
            }
            power = (power * 2) % MOD;
            bit++;
            n/=2;
        }
        return (int)sum;
    }
    int concatenatedBinary(int n) {
        long long ans=0;
        // int bit=0;
        for(int i=n;i>=1;i--){
            ans+=add(i);
            ans%=MOD;
        }
        return (int)ans;
    }
};