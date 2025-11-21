class Solution1 {
public:
    unordered_set<string>st;
    void solve(int i,string s,string curr){
        if(curr.size()==3){
            string a=curr;
            reverse(a.begin(),a.end());
            if(curr==a){
                if(!st.count(curr)){
                    st.insert(curr);
                    cout<<curr<<" ";
                }
            }
            return;
        }
        if(curr.size()>3) return;
        if(i==s.size()) return;
        curr.push_back(s[i]);
        solve(i+1,s,curr);
        curr.pop_back();
        solve(i+1,s,curr);
    }
    int countPalindromicSubsequence(string s) {
        string curr;
        solve(0,s,curr);
        return st.size();
    }
};
class Solution2 {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
        unordered_set<string>st;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(s[i]==s[j]){
                unordered_set<char>mid;
                    for(int u=i+1;u<j;u++){
                        mid.insert(s[u]);
                    }
                    for(auto it:mid){
                        string curr="";
                        curr+=s[i];
                        curr+=it;
                        curr+=s[i];
                        st.insert(curr);
                        cout<<curr<<" ";
                    }
                }
            }
        }
        return st.size();
    }
};
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
        unordered_set<string>st;
        vector<int>first(26,-1),last(26,-1);
        for(int i=0;i<n;i++){
            if(first[s[i]-'a']==-1) first[s[i]-'a']=i;
            last[s[i]-'a']=i;
        }
        for(int i=0;i<26;i++){
            if(first[i]!=-1 && first[i]!=last[i]){
                unordered_set<char>mid;
                    for(int u=first[i]+1;u<last[i];u++){
                        mid.insert(s[u]);
                    }
                    for(auto it:mid){
                        string curr="";
                        curr+=s[first[i]];
                        curr+=it;
                        curr+=s[first[i]];
                        st.insert(curr);
                        cout<<curr<<" ";
                    }
                }
            }
        return st.size();
    }
};