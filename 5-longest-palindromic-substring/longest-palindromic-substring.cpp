class Solution1 {
public:
    string ans="";
    bool ispal(int i,int j,string &s){
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(int i,int j,string &s){
        if(i>j || (j-i+1)<ans.size()) return ;
        if(ispal(i,j,s)){
            int u=j-i+1;
            if(u>ans.size()){
                ans=s.substr(i,u);
            }
        }   
        solve(i+1,j,s);
        solve(i,j-1,s);
        return;
    }
    string longestPalindrome(string s) {
       int n=s.size();
       solve(0,n-1,s);
       return ans;
    }
};
class Solution {
public:
    string longestPalindrome(string s) {
       int n=s.size();
       string ans="";
       int start=0,maxLen=0;
       auto expand=[&](int l,int r){
        while(l>=0 && r<n && s[l]==s[r]){
            if(r-l+1>maxLen){
                maxLen=(r-l+1);
                start=l;
            }
            l--;
            r++;
        }
       };
       for(int i=0;i<n;i++){
            expand(i,i);
            expand(i,i+1);
       }
       return s.substr(start,maxLen);
    }
};