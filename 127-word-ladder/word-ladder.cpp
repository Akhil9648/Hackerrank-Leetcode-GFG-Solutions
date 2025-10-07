class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty()){
            string wrd=q.front().first;
            int level=q.front().second;
            q.pop();
            if(wrd==endWord) return level;
            for(int i=0;i<wrd.size();i++){
                char org=wrd[i];
                for(char c='a';c<='z';c++){
                    wrd[i]=c;
                    if(st.find(wrd)!=st.end()){
                        q.push({wrd,level+1});
                        st.erase(wrd);
                    }
                }
                wrd[i]=org;
            }
        }
        return 0;
    }
};