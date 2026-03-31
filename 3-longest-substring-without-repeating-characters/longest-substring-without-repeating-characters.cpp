class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;
        int n=s.size();
        int i=0,j=0;
        int ans=0;
        while(j<n){
            while(st.count(s[j])){
                st.erase(s[i]);
                i++;
            }
            st.insert(s[j]);
            ans=max(ans,(j-i+1));
            j++;
        }
        return ans;
    }
};