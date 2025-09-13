class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        int number=0,sign=1,result=0;
        for(char c:s){
            if(isdigit(c)) number=(number*10)+(c-'0');
            else if(c=='+'){
                result+=(number*sign);
                number=0;
                sign=1;
            }
           else  if(c=='-'){
                result+=(number*sign);
                number=0;
                sign=-1;
            }
            else if(c=='('){
                st.push(result);
                st.push(sign);
                result=0;
                sign=1;
                number=0;
            }
            else if(c==')'){
                result+=(number*sign);
                number=0;
                int sig=st.top();
                st.pop();
                result*=sig;
                result+=st.top();
                st.pop();
            }
        }
        result+=(number*sign);
        return result;
    }
};