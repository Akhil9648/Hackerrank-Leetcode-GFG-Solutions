class Solution {
public:
    string largestEven(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        int n=t.size();
        int j=0;
        while(j<n){
            if((t[j]-'0')%2==0){
                break;
            }
            t.erase(t.begin(),t.begin()+1);
        }
        reverse(t.begin(),t.end());
        return t;
    }
};