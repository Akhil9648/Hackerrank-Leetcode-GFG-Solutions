class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        vector<int>fre1(26,0),fre2(26,0);
        for(char i:word1){
            fre1[i-'a']++;
        }
        for(char i:word2){
            fre2[i-'a']++;
        }
        for(int i=0;i<26;i++){
            if((fre1[i]!=0 && fre2[i]==0) || (fre1[i]==0 && fre2[i]!=0) ) return false;
        }
        sort(fre1.begin(),fre1.end());
        sort(fre2.begin(),fre2.end());
        return fre1==fre2;
    }
};