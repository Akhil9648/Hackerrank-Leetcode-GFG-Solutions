class Solution {
public:
    vector<vector<int>>checkLCP(string s){
        int n=s.size();
        vector<vector<int>>LCP(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            if(s[n-1]==s[i]){
                LCP[i][n-1]=1;
                LCP[n-1][i]=1;
            }
        }
        for(int i=n-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                if(s[i]==s[j]){
                    LCP[i][j]=1+LCP[i+1][j+1];
                }
            }
        }
        return LCP;
    }
    string findTheString(vector<vector<int>>& lcp) {
        int n=lcp.size();
        string ans(n,'$');
        if(lcp[0][0]!=0) ans[0]='a';
        else return "";
        for(int i=1;i<n;i++){
            for(int j=1;j<=i;j++){
                if(lcp[i][j]!=0){
                    ans[i]=ans[j];
                    break;
                }
            }
            if(ans[i]=='$'){
                vector<bool>freq(26,false);
                for(int j=0;j<i;j++){
                    if(lcp[i][j]==0){
                        freq[ans[j]-'a']=true;
                    }
                }
                for(int j=0;j<26;j++){
                    if(!freq[j]){
                        ans[i]=j+'a';
                        break;
                    }
                }
                if(ans[i]=='$') return "";
            }
        }
        return checkLCP(ans)==lcp?ans:"";
    }
};