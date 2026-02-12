class Solution {
public:
    bool isbalanced(int i,int j,unordered_map<char,int>& mp,int cnt){
        for(auto it:mp){
            if(it.second!=cnt) return false;
        }
        return true;
    }
    int longestBalanced(string s) {
        int n=s.size();
        int maxi=0;
        for(int i=0;i<n;i++){
        unordered_map<char,int>mp;
            for(int j=i;j<n;j++){
                mp[s[j]]++;
                if(isbalanced(i,j,mp,mp[s[i]])){
                    maxi=max(maxi,j-i+1);
                }
            }
        }
        return maxi;
    }
};