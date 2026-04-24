class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n=moves.size();
        int l=0,r=0;
        for(char c:moves){
            if(c=='L') l++;
            else if(c=='R') r++;
        }
        int a=n-(l+r);
        int res=abs(l-r);
        a+=res;
        return a;
    }
};