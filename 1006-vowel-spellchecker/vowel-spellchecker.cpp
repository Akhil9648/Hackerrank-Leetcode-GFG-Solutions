class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string>exact(wordlist.begin(),wordlist.end());
        unordered_map<string,string>first;
        for(auto it:wordlist){
            string b=it;
            transform(b.begin(),b.end(),b.begin(),::tolower);
            if(first.find(b)==first.end()){
                first[b]=it;
            }
        }
        unordered_map<string,string>fetch;
        for(auto it:wordlist){
            string a=it;
            transform(a.begin(),a.end(),a.begin(),::tolower);
            for(auto &c:a){
                if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
                    c='*';
                }
            }
            if(fetch.find(a)==fetch.end()){
                fetch[a]=it;
            }
        }
        vector<string>ans;
        for(auto it:queries){
            string b=it;
            transform(b.begin(),b.end(),b.begin(),::tolower);
            if(exact.find(it)!=exact.end()){
                ans.push_back(it);
                continue;
            }
            else if(first.find(b)!=first.end()){
                ans.push_back(first[b]);
                continue;
            }
            else{
                for(auto &c:b){
                if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
                    c='*';
                        }
                }
                if(fetch.find(b)!=fetch.end()){
                    ans.push_back(fetch[b]);
                }
                else{
                    ans.push_back("");
                }
            }
        }
        return ans;
    }
};