class Solution {
public:
    string generateString(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();
        string ans(n+m-1,'$');
        for(int i=0;i<n;i++){
            if(str1[i]=='T'){
                for(int j=i;j<i+m;j++){
                    if(ans[j]!='$' && ans[j]!=str2[j-i]) return "";
                    ans[j]=str2[j-i];
                }
            }
        }
        vector<int>canchange(n+m-1,0);
        for(int i=0;i<n+m-1;i++){
            if(ans[i]!='$'){
                canchange[i]=1;
            }
            else{
                ans[i]='a';
            }
        }
        for(int i=0;i<n;i++){
            if(str1[i]=='F'){
                string s=ans.substr(i,m);
                if(s==str2){
                    bool changed=false;
                    for(int u=i+m-1;u>=i;u--){
                        if(canchange[u]) continue;
                        if(ans[u]=='z') ans[u]--;
                        else ans[u]++;
                        changed=true;
                        break;
                    }
                    if(!changed) return "";
                }
            }
        }
        return ans;
    }
};