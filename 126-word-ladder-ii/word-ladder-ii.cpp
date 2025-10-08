// Approach-1 MLE TC-33
// But this will be the approach for the interviews
class Solution1 {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        vector<vector<string>>ans;
        vector<string>used;
        if (!st.count(endWord)) return ans;
        queue<vector<string>>q;
        q.push({beginWord});
        int level=1;
        while(!q.empty()){
            vector<string>curr=q.front();
            q.pop();
            string a=curr.back();
            if(curr.size()>level){
                level++;
                for(auto it:used){
                    st.erase(it);
                }
                used.clear();
            }
            if(a==endWord){
                if(ans.size()==0) ans.push_back(curr);
                else if(ans[0].size()==curr.size()) ans.push_back(curr);
            }
            for(int i=0;i<a.size();i++){
                char org=a[i];
                for(char c='a';c<='z';c++){
                    a[i]=c;
                    if(st.find(a)!=st.end()){
                        if((!q.empty() && curr.size()<q.front().size()) || q.empty()) st.erase(a); 
                        curr.push_back(a);
                        q.push(curr);
                        used.push_back(a);
                        curr.pop_back();
                    }
                }
                a[i]=org;
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string,int> mp; // distance from beginWord
    string b;

    void dfs(string word, vector<string>& seq) {
        if (word == b) {
            vector<string> path = seq;
            reverse(path.begin(), path.end());
            ans.push_back(path);
            return;
        }
        int steps = mp[word];
        int sz = (int)word.size();
        for (int i = 0; i < sz; i++) {
            char org = word[i];
            for (char c = 'a'; c <= 'z'; c++) {
                if (c == org) continue;
                word[i] = c;
                auto it = mp.find(word);
                if (it != mp.end() && it->second + 1 == steps) {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = org;
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        b = beginWord;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return ans; // no solution if endWord not in dict [web:274]

        queue<string> q;
        q.push(beginWord);
        mp.clear();
        mp[beginWord] = 1;

        bool found = false;
        int L = (int)beginWord.size();

        while (!q.empty() && !found) {
            int sz = q.size();
            unordered_set<string> usedThisLevel; // words discovered in this level
            while (sz--) {
                string a = q.front(); q.pop();
                int steps = mp[a];
                string w = a;
                for (int i = 0; i < L; i++) {
                    char org = w[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == org) continue;
                        w[i] = c;
                        if (w == endWord) {
                            // record endWord distance but do not early break current level
                            if (!mp.count(w)) mp[w] = steps + 1;
                            found = true;
                        }
                        if (dict.count(w)) {
                            if (!mp.count(w)) mp[w] = steps + 1; // first time distance
                            if (!usedThisLevel.count(w)) {
                                q.push(w);
                                usedThisLevel.insert(w);
                            }
                        }
                    }
                    w[i] = org;
                }
            }
            // remove all words found in this level so other paths in this level can add them as predecessors
            for (auto &w : usedThisLevel) dict.erase(w);
        }

        if (mp.find(endWord) != mp.end()) {
            vector<string> seq{endWord};
            dfs(endWord, seq);
        }
        return ans;
    }
};
