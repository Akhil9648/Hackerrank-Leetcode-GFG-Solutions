class Solution {
public:
    void solve(int n,int i,int j,vector<string>& ans,string &s){
            if(s.size()==n*2)
            {
                ans.push_back(s);
                return;
            }
        if(i<n){
            s.push_back('(');
            solve(n,i+1,j,ans,s);
            s.pop_back();
        }
        if(j<i){
            s.push_back(')');
            solve(n,i,j+1,ans,s);
            s.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s;
        solve(n,0,0,ans,s);
        return ans;
    }
};