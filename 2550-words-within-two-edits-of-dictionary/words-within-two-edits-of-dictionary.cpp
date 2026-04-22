class Solution {
public:
    bool check(int m,string &a,string &b){
        int cnt=0;
        for(int i=0;i<m;i++){
            if(a[i]!=b[i]) cnt++;
            if(cnt>2) return false;
        }
        return true;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n=queries.size();
        int m=queries[0].size();
        int k=dictionary.size();
        vector<string>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<k;j++){
                if(check(m,queries[i],dictionary[j])){
                    ans.push_back(queries[i]);
                    break;
                }
            }
        }
        return ans;
    }
};