class Solution {
public:
int n;
    int helper(char a,char b,string &s){
        unordered_map<int,int>mp;
        int maxi=0;
        int cnta=0,cntb=0;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            if(s[i]==a){
                cnta++;
            }
            else if(s[i]==b){
                cntb++;
            }
            else{
                cnta=0;
                cntb=0;
                mp.clear();
                continue;
            }
             if(cnta == cntb) {
                maxi = max(maxi, cnta+cntb);
            }
            int diff=cnta-cntb;
            if(mp.find(diff)!=mp.end()){
                maxi=max(maxi,i-mp[diff]);
            }
            else mp[diff]=i;
        }
        return maxi;
    }
    int longestBalanced(string s) {
        n=s.size();
        int maxi=1,cnt=1;
        char curr=s[0];
        for(int i=1;i<n;i++){
            if(s[i]==curr){
                cnt++;
            }
            else{
                curr=s[i];
                maxi=max(maxi,cnt);
                cnt=1;
            }
        }
        maxi=max(maxi,cnt);
        int a=helper('a','b',s);
        maxi=max(maxi,a);
        a=helper('a','c',s);
        maxi=max(maxi,a);
        a=helper('b','c',s);
        maxi=max(maxi,a);
        map<pair<int,int>,int>mp;
        int cnta=0,cntb=0,cntc=0;
        mp[{0,0}]=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                cnta++;
            }
            else if(s[i]=='b'){
                cntb++;
            }
            else cntc++;
            int diffa=cnta-cntb;
            int diffb=cnta-cntc;
            if(mp.find({diffa,diffb})!=mp.end()){
                maxi=max(maxi,i-mp[{diffa,diffb}]);
            }
            else mp[{diffa,diffb}]=i;
        }
        return maxi;
    }
};