class Solution {
public:
    string decodeString(string s) {
        string ans="";
        int n=s.size();
        stack<int>st;
        stack<string>ch;
        int num=0;
        for(int i=0;i<n;i++){
            if(s[i]>='0' && s[i]<='9'){
                num=num*10+(s[i]-'0');
            }
            else if(s[i]=='['){
                st.push(num);
                num=0;
                ch.push(ans);
                ans="";
            }
            else if(s[i]==']'){
                string bfr=ans;
                ans=ch.top();
                ch.pop();
                int a=st.top();
                st.pop();
                while(a--){
                    ans+=bfr;
                }
            }
            else{
                ans+=s[i];
            }
        }
        return ans;
    }
};