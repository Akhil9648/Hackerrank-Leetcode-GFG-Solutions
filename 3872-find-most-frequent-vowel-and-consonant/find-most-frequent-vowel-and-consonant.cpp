class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int>vow,cons;
        for(char c:s){
            if(c=='a' || c=='e' || c=='i' ||  c=='o' || c=='u'){
                vow[c]++;
            }
            else{
                cons[c]++;
            }
        }
        int maxiv=0,maxic=0;
        for(auto it:vow){
            maxiv=max(maxiv,it.second);
        }
        for(auto it:cons){
            maxic=max(maxic,it.second);
        }
        return maxiv+maxic;
    }
};