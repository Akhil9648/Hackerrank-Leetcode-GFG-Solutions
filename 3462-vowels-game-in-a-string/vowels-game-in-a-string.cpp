class Solution {
public:
    bool doesAliceWin(string s) {
        int i=0;
        while(i<s.size()){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') return true;
            i++;
        }
        return false;
    }
};