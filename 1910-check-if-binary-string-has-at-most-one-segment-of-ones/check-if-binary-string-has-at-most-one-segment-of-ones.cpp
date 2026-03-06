class Solution {
public:
    bool checkOnesSegment(string s) {
        int n=s.size();
        int curr=0,total=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1') curr++;
            else{
                if(curr>0) total++;
                curr=0;
            }
        }
        if(curr>0) total++;
        return total==1;
    }
};