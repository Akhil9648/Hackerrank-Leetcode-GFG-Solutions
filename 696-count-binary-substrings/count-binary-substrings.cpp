class Solution {
public:
    int countBinarySubstrings(string s) {
        int cnt=0;
        int curr=1;
        int prev=0;
        int n=s.size();
        for(int i=1;i<n;i++){
            if(s[i]!=s[i-1]){
                cnt+=min(curr,prev);
                prev=curr;
                curr=1;
            }
            else curr++;
        }
        cnt+=min(curr,prev);
        return cnt;
    }
};