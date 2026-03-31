class Solution1 {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        sort(p.begin(),p.end());
        int n=s.size();
        int m=p.size();
        for(int i=0;i<n;i++){
            string a=s.substr(i,m);
            sort(a.begin(),a.end());
            if(a==p) ans.push_back(i);
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        int n=s.size();
        int m=p.size();
        unordered_map<char,int>mp1,mp2;
        for(auto it:p){
            mp2[it]++;
        }
        int j=0;
        for(int i=0;i<n;i++){
            if(i-j>=m){
                mp1[s[j]]--;
                if(mp1[s[j]]==0) mp1.erase(s[j]);
                j++;
            }
            mp1[s[i]]++;
            if(mp1==mp2) ans.push_back(j);
        }
        return ans;
    }
};