class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int>st;
        for(auto it:friendships){
            int a=it[0]-1;
            int b=it[1]-1;
            unordered_set<int>lang(languages[a].begin(),languages[a].end());
            bool ct=false;
            for(int lan:languages[b]){
                if(lang.find(lan)!=lang.end()){
                    ct=true;
                    break;
                }
            }
                if(!ct){
                    st.insert(a);
                    st.insert(b);
                }
            }
        int most=0;
        vector<int>lang(n+1,0);
        for(int i:st){
            for(int j:languages[i]){
                lang[j]++;
                most=max(most,lang[j]);
            }
        }
        return st.size()-most;
    }
};