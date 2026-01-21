class Solution {
public:
    bool isVowel(char c){
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
        return false;
    }
    int vowelConsonantScore(string s) {
        int c=0,v=0;
        for(char i:s){
            if(isVowel(i)) v++;
            else if(i>='a' && i<='z') c++;
        }
        if(c==0) return 0;
        return floor(v/c);
    }
};