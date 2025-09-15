class Solution1 {
public:
    int canBeTypedWords(string text, string bro) {
        unordered_set<int>st;
        for(char c:bro){
            st.insert(c);
        }
        stringstream ss(text);
        string word;
        vector<string>words;
        while(ss>>word){
            words.push_back(word);
        }
        int ans=0;
        for(auto s:words){
                int flag=0;
            for(char c:s){
                if(st.find(c)!=st.end()){
                    flag=1;
                    break;
                }
            }
            if(!flag) ans++;
        }
        return ans;
    }
};
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {

        int n=text.size();
        unordered_set<char> s;
        int elements=1;

        for(int i=0; i<brokenLetters.size(); i++){
            s.insert(brokenLetters[i]);
        }
        for(int k=0; k<text.size(); k++){
            if(text[k]==' ') elements++;
        }

        for(int j=0; j<text.size(); j++){
           if(s.find(text[j])!=s.end()){
             elements--;
            while(j < text.size() && text[j] != ' '){
                j++;
            }
           }
        }
        return elements;
    }
};