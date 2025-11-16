class Solution {
public:
    int numSub(string s) {
        int MOD=1e9+7;
        int one=0,ans=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                int a = ( (1LL * one * (one + 1) / 2) % MOD );
                ans=(ans+a)%MOD;
                one=0;
            }
            else{
                one++;
            }
        }
        if(one>0){
            int a = ( (1LL * one * (one + 1) / 2) % MOD );
                ans=(ans+a)%MOD;
        }
        return ans;
    }
};