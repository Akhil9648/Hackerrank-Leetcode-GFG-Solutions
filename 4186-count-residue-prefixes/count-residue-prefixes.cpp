class Solution {
public:
    int residuePrefixes(string s) {
        int n=s.size(),count=0;
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            if((i+1)%3==mp.size()) count++;
        }
        return count;
    }
};