class Solution {
public:
    long long removeZeros(long long n) {
        string s=to_string(n);
        string ans="";
        int a=s.size();
        for(int i=0;i<a;i++){
            if(s[i]!='0') ans+=s[i];
        }
        return stoll(ans);
    }
};