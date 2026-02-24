class Solution1 {
public:
    int findmax(char c,string &s,int i){
        int maxi=0;
        for(;i<s.size();i++){
            if(s[i]==c) maxi=max(maxi,i);
        }
        return maxi;
    }
    vector<int> partitionLabels(string s) {
        int n=s.size();
        unordered_set<char>st;
        vector<int>ans;
        for(int i=0;i<n;i++){
            int maxi=findmax(s[i],s,i);
            st.insert(s[i]);
            for(int j=i+1;j<maxi;j++){
                if(!st.count(s[j])) maxi=max(maxi,findmax(s[j],s,j));
            }
            ans.push_back(maxi-i+1);
            i=maxi;
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]]=i;
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            int maxi=mp[s[i]];
            for(int j=i+1;j<=maxi;j++){
                maxi=max(maxi,mp[s[j]]);
            }
            ans.push_back(maxi-i+1);
            i=maxi;
        }
        return ans;
    }
};