class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.size(),m=t.size();
        if(n==0) return true;
        int j=0,i=0;
        while(j<n && i<m){
            if(s[j]==t[i]){
                j++;
            }
            i++;
        }
        return j==n;
    }
};