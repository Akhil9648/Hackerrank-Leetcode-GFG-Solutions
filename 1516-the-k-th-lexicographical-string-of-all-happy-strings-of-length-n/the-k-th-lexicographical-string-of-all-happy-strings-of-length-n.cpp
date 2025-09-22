class Solution {
public:
    void solve(int n,int &k,string &s,string &ans){
        if(s.length()==n){
            k--;
            if(k==0){
                ans=s;
            }
            return;
        }
        for(char ch='a';ch<='c';ch++){
            if(!s.empty() && s.back()==ch){
                continue;
            }
            s.push_back(ch);
            solve(n,k,s,ans);
            if(!ans.empty()) return;
            s.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        string curr="",ans="";
        solve(n,k,curr,ans);
        return ans;
    }
};