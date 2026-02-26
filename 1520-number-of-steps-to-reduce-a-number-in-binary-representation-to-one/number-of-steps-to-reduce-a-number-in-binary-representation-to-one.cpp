class Solution1 {
public:
    int numSteps(string s) {
        reverse(s.begin(),s.end());
        int a=0,n=0;
        for(char c:s){
            if(c=='1'){
                n+=pow(2,a);
            }
            a++;
        }
        a=0;
        while(n>1){
            if(n%2==0) n/=2;
            else n++;
            a++;
        }
        return a;
    }
};
class Solution2 {
public:
    int numSteps(string s) {
        reverse(s.begin(),s.end());
        int cnt=0;
        while(s.size()>1){
            if(s[0]=='0'){
                s.erase(0,1);
            }
            else{
                int i=0;
                while(i<s.size() && s[i]=='1'){
                    s[i]='0';
                    i++;
                }
                if(i<s.size()) s[i]='1';
                else s.push_back('1');
            }
            cnt++;
        }
        return cnt;
    }
};
class Solution {
public:
    int numSteps(string s) {
        reverse(s.begin(),s.end());
        int carry=0,step=0;
        int n=s.size();
        int i=0;
        while(i<n-1){
            if(s[i]-'0'+carry==1){
                step+=2;
                carry=1;
            }
            else{
                step++;
            }
            i++;
        }
        return step+carry;
    }
};