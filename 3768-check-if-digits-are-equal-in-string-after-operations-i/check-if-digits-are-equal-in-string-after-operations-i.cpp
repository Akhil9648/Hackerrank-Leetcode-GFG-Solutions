class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size()>2){
            int n=s.size();
            string curr="";
            for(int i=0;i<n-1;i++){
                int a=s[i]-'0';
                int b=s[i+1]-'0';
                a=(a+b)%10;
                curr+=(a+'0');
            }
            s=curr;
        }
        return s[0]==s[1];
    }
};