class Solution {
public:
    int lengthOfLastWord(string s) {
        reverse(s.begin(),s.end());
        int n=s.length();
        int i=0,u=0;
        while(s[i]==' '){
            i++;
            u++;
        }
        while(i<n && s[i]!=' '){
            i++;
        }
        return i-u;
    }
};