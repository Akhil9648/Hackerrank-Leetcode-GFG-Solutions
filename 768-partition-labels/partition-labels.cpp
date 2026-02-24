class Solution {
public:
    int findmax(char c,string &s){
        int maxi=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==c) maxi=max(maxi,i);
        }
        return maxi;
    }
    vector<int> partitionLabels(string s) {
        int n=s.size();
        unordered_set<char>st;
        vector<int>ans;
        for(int i=0;i<n;i++){
            int maxi=findmax(s[i],s);
            st.insert(s[i]);
            for(int j=i+1;j<maxi;j++){
                if(!st.count(s[j])) maxi=max(maxi,findmax(s[j],s));
            }
            ans.push_back(maxi-i+1);
            i=maxi;
        }
        return ans;
    }
};