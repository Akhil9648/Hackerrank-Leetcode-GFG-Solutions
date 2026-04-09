class Solution1 {
public:
int n;
    int solve(string beginWord,string endWord,unordered_set<string>& st,int q){
        if(beginWord==endWord) return q+1;
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            char org=beginWord[i];
            for(int j=0;j<26;j++){
                beginWord[i]='a'+j;
                if(st.count(beginWord)){
                    st.erase(beginWord);
                    cout<<beginWord<<" "<<i<<endl;
                    int a=solve(beginWord,endWord,st,q+1);
                    ans=min(ans,a);
                    st.insert(beginWord);
                }
            }
            beginWord[i]=org;
        }
        return ans;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st;
        for(auto it:wordList){
            st.insert(it);
        }
        n=beginWord.length();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            char org=beginWord[i];
            for(int j=0;j<26;j++){
                beginWord[i]='a'+j;
                if(st.count(beginWord)){
                    st.erase(beginWord);
                    cout<<beginWord<<" "<<i<<endl;
                    int a=solve(beginWord,endWord,st,1);
                    ans=min(ans,a);
                    st.insert(beginWord);
                }
            }
            beginWord[i]=org;
        }
        return ans==INT_MAX?0:ans;
    }
};
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st;
        for(auto it:wordList){
            st.insert(it);
        }
        int n=beginWord.length();
        int ans=INT_MAX;
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            string wrd=it.first;
            int dis=it.second;
            if(wrd==endWord) return dis;
            for(int i=0;i<n;i++){
                char org=wrd[i];
                for(int j=0;j<26;j++){
                    wrd[i]='a'+j;
                    if(st.count(wrd)){
                        q.push({wrd,dis+1});
                        st.erase(wrd);
                    }
                }
                wrd[i]=org;
            }
        }
        return 0;
    }
};