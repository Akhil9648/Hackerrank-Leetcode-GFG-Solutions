class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n=s1.size();
        for(int i=0;i<n;i++){
            if(s1[i]==s2[i]) continue;
            for(int j=i+2;j<n;j+=2){
                if(s2[i]==s1[j]){
                    swap(s1[i],s1[j]);
                    break;
                }
            }
            if(s1[i]!=s2[i]) return false;
        }
        return s1==s2;
    }
};