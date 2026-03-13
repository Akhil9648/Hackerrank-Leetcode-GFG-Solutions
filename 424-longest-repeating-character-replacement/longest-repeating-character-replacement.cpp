class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>res(26,0);
        int n=s.size();
        int i=0,j=0,maxi=0,b=0;
        while(j<n){
            res[s[j]-'A']++;
            b=max(b,res[s[j]-'A']);
            if((j-i+1)-k>b){
                res[s[i]-'A']--;
                i++;
            }
            maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};