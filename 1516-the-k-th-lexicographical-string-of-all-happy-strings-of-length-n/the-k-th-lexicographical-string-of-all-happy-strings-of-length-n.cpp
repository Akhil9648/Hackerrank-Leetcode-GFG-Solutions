class Solution {
public:
    vector<char>vec={'a','b','c'};
    void solve(int n,string &s,vector<string>& ans){
        if(n==0){
            ans.push_back(s);
            return;
        }
        for(int i=0;i<3;i++){
            if(!s.empty() && s.back()==vec[i]) continue;
            s.push_back(vec[i]);
            solve(n-1,s,ans);
            s.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        vector<string>ans;
        string s;
        solve(n,s,ans);
        if(k>ans.size()) return "";
        return ans[k-1];
    }
};