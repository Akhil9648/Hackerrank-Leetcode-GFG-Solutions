class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans="";
        int n=min(word1.size(),word2.size());
        int i=0,j=0;
        while(i<n && j<n){
            ans+=word1[i];
            i++;
            ans+=word2[j];
            j++;
        }
        while(i<word1.size()){
            ans+=word1[i];
            i++;
        }
        while(j<word2.size()){
            ans+=word2[j];
            j++;
        }
        return ans;
    }
};