class Solution {
public:
    int trya(string &s,int n){
        int cnt=0;
        char a='0';
        cout<<s[0]-'0'<<" "<<a-'0';
        for(int i=0;i<n;i++){
            if(s[i]!=a) cnt++;
            if(a=='1') a='0';
            else a='1';
        }
        return cnt;
    }
    int tryb(string &s,int n){
        int cnt=0;
        if(s[0]=='0') cnt++;
        char a='0';
        for(int i=1;i<n;i++){
            if(s[i]!=a) cnt++;
            if(a=='1') a='0';
            else a='1';
        }
        return cnt;
    }
    int minOperations(string s) {
        int n=s.size();
        return min(trya(s,n),tryb(s,n));
        // return cnt;
    }
};