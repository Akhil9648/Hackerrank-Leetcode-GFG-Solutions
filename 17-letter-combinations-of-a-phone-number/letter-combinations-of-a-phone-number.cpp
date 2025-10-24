class Solution {
public:
    void solve(int i,int n,vector<string>& ans,string curr,string digits,unordered_map<char,string>&mp){
        if(i==n){
            ans.push_back(curr);
            return;
        }
        for(auto it:mp[digits[i]]){
            curr.push_back(it);
            solve(i+1,n,ans,curr,digits,mp);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        int n=digits.size();
        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        solve(0,n,ans,"",digits,mp);
        return ans;   
    }
};