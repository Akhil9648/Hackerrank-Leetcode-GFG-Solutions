class Solution {
public:
    bool check(unordered_map<char,int>& mp1,unordered_map<char,int>& mp2){
        for(auto it:mp1){
            if(!mp2.count(it.first)) return false;
            if(mp2[it.first]<it.second) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int>mp1,mp2;
        for(char c:p){
            mp1[c]++;
        }
        int n=s.size();
        int k=p.size();
        for(int i=0;i<k;i++){
            mp2[s[i]]++;
        }
        int i=0,j=k;
        vector<int>ans;
        while(j<n){
            if(check(mp1,mp2)) ans.push_back(i);
            mp2[s[i]]--;
            mp2[s[j]]++;
            i++;
            j++;
        }
        if(check(mp1,mp2)) ans.push_back(i);
        return ans;
    }
};