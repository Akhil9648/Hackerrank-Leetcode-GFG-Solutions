class Solution {
public:
    string lexSmallest(string s) {
        int n=s.size();
        string a=s,b=s;
        for(int i=0;i<n;i++){
            b=s;
            reverse(b.begin(),b.begin()+i);
            a=min(a,b);
        }
        for(int i=n-1;i>=0;i--){
            b=s;
            reverse(b.begin()+i,b.end());
            a=min(a,b);
        }
        return a;
    }
};