class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        int n=num.size();
        if(k==n) return "0";
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top()>num[i] && k-->0) st.pop();
            st.push(num[i]);
        }
        while(k>0){
            st.pop();
            k--;
        }
        string ans="";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            while(ans[i]=='0') ans.erase(i,1);
            if(ans[i]!='0') break;
        }
        return ans==""?"0":ans;
    }
};