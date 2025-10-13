class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>ans;
        ans.push_back(words[0]);
        int n=words.size();
        for(int i=1;i<n;i++){
            string a=words[i-1];
            string b=words[i];
            string c=b;
            sort(a.begin(),a.end());
            sort(b.begin(),b.end());
            if(a==b) continue;
            ans.push_back(c);
        }
        return ans;
    }
};