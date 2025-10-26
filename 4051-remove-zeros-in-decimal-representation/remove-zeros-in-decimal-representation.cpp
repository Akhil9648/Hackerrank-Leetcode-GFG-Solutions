class Solution {
public:
    long long removeZeros(long long n) {
        string s=to_string(n);
        // string ans="";
        int a=s.size();
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                s.erase(s.begin()+i); 
                i--;
            }
        }
        return stoll(s);
    }
};