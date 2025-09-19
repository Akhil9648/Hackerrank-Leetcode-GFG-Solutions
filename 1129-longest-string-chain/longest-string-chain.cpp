class Solution {
public:
    bool check(string &s1,string &s2){
        int a=0,b=0;
        if(s1.size()!=s2.size()+1) return false;
        while(a<s1.size()){
            if(s1[a]==s2[b]){
                a++;
                b++;
            }
            else{
                a++;
            }
        }
        if(a==s1.size() && b==s2.size()) return true;
        return false;
    }
    // bool comp(string &s1,string &s2){
    //     return s1.size()<s2.size();
    // }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](const string &s1,const string &s2){
            return s1.size()<s2.size();
        });
        int maxi=0;
        int n=words.size();
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(check(words[i],words[j]) && dp[i]<1+dp[j]){
                    dp[i]=1+dp[j];
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};