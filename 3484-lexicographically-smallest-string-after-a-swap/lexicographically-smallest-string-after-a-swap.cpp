class Solution {
public:
    string getSmallestString(string s) {
        int n=s.size();
        string t=s;
        for(int i=0;i<n-1;i++){
            int a=t[i]-'0';
            int b=t[i+1]-'0';
            if(a>b){
            if(a%2==0 && b%2==0){
                swap(t[i],t[i+1]);
                break;
            }
            else if(a%2==1 && b%2==1){
                swap(t[i],t[i+1]);
                break;
            }
            }
        }
        return t;
    }
};