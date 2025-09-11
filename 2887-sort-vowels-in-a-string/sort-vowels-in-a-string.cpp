class Solution {
public:
    string sortVowels(string s) {
        unordered_set<char>st;
        st.insert('A'); st.insert('E'); st.insert('I'); st.insert('O'); st.insert('U');
        st.insert('a'); st.insert('e'); st.insert('i'); st.insert('o'); st.insert('u');
        vector<char>str;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(st.find(s[i])!=st.end()){
                str.push_back(s[i]);
                s[i]=-1;
            }
        }
        sort(begin(str),end(str));
        int j=0;
        for(int i=0;i<n;i++){
            if(s[i]==-1){
                s[i]=str[j];
                j++;
            }
        }
        return s;
    }
};