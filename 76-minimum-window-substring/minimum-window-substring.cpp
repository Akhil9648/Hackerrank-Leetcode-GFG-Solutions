class Solution1 {
public:
bool check(unordered_map<char,int>&curr,unordered_map<char,int>& req){
        for(auto it:req){
            char c=it.first;
            if(!curr.count(c) || curr[c]<it.second) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        unordered_map<char,int>curr,req;
        for(auto it:t){
            req[it]++;
        }
        int n=s.size();
        int i=0,j=0;
        string ans="";
        int cnt=INT_MAX;
        while(j<n){
            curr[s[j]]++;
            bool chk=false;
            if(curr.size()>=req.size()){
                chk=check(curr,req);
            }
            while(chk && i<n){
                if(cnt>(j-i+1)){
                    cnt=j-i+1;
                    ans=s.substr(i,cnt);
                    if(ans.size()==1) return ans;
                }
                curr[s[i]]--;
                if(req.count(s[i])){
                    if(curr[s[i]]<req[s[i]]) chk=false;
                }
                if(curr[s[i]]==0) curr.erase(s[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        int cnt=0;
        for(char c:t) mp[c]++;
        int n=s.size();
        int ans=INT_MAX,st=n;
        int i=0,j=0;
        while(j<n){
            if(mp[s[j]]>0) cnt++;
            while(cnt==t.size()){
                if(ans>(j-i+1)){
                    ans=j-i+1;
                    st=i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0) cnt--;
                i++;
            }
            mp[s[j]]--;
            j++;
        }
        return s.substr(st,ans);
    }
};
