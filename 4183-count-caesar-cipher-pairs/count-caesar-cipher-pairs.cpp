class Solution {
public:
    void convert(string &s) {
    int shift = s[0] - 'a';   // how much to shift backward
    for (int i = 0; i < s.size(); i++) {
        s[i] = ( (s[i] - 'a' - shift + 26) % 26 ) + 'a';
    }
}
    long long countPairs(vector<string>& words) {
        int n=words.size();
        unordered_map<string,int>st;
        long long count=0;
        for(int i=0;i<n;i++){
            string s=words[i];
            convert(s);
            st[s]++;
        }
        for(auto it:st){
            int a=it.second;
            count+=(1LL*a*(a-1)/2);
        }
        return count;
    }
};