class Solution1 {
public:
    string conv(long long n,int k){
        string str;
        while(n){
            int d=n%2;
            n/=2;
            str.push_back(d+'0');
        }
        while(str.size()<k) str.push_back('0');
        reverse(str.begin(),str.end());
        return str;
    }
    bool hasAllCodes(string s, int k) {
        long long n=pow(2,k);
        int u=s.size();
        while(n--){
            int flag=0;
            for(int i=0;i<=u-k;i++){
                if(s.substr(i,k)==conv(n,k)){
                    flag=1;
                    break;
                }
            }
            if(!flag) return false;
        }
        return true;
    }
};
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string>st;
        int u=s.size();
        for(int i=0;i<=u-k;i++){
            st.insert(s.substr(i,k));
        }
        return st.size()==1<<k;
    }
};