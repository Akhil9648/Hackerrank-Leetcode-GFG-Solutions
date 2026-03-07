class Solution1 {
public:
int n;
    int solve(string &s,int i,int prev,vector<vector<int>>& dp){
        if(i>=n) return 0;
        if(dp[i][prev]!=-1) return dp[i][prev];
        int take=INT_MAX,notTake=INT_MAX;
        if(s[i]!=prev+'0'){
            take=solve(s,i+1,s[i]-'0',dp);
        }
        else{
            take=1+solve(s,i+1,s[i]-'0',dp);
            if(s[i]=='0') notTake=1+solve(s,i+1,1,dp);
            else notTake=1+solve(s,i+1,0,dp);
        }
        return dp[i][prev]=min(take,notTake);
    }
    int minFlips(string s) {
        n=s.size();
        while(s[n-1]!=s[0]){
            s.push_back(s[0]);
            s.erase(0,1);
        }
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(s,1,s[0]-'0',dp);
    }
};
class Solution {
public:
    int minFlips(string s) {
        int n=s.size();
        string dup=s;
        dup+=s;
        string comp1="",comp2="";
        int a=0;
        for(int i=0;i<2*n;i++){
            if(a){
                comp1+="0";
                comp2+="1";
            }
            else{
                comp1+="1";
                comp2+="0";
            }
            a=!a;
        }
        vector<int>a1(2*n,0),a2(2*n,0);
        for(int i=0;i<2*n;i++){
            if(dup[i]!=comp1[i]){
                a1[i]=1;
            }
            if(dup[i]!=comp2[i]){
                a2[i]=1;
            }
        }
        int curr1=0,curr2=0;
        int mini=INT_MAX;
        for(int i=0;i<2*n;i++){
            if(i>=n){
                mini=min(mini,curr1);
                mini=min(mini,curr2);
                curr1-=a1[i-n];
                curr2-=a2[i-n];
            }
            curr1+=a1[i];
            curr2+=a2[i];
        }
        return mini;
    }
};