class Solution {
public:
    int binaryGap(int n) {
        int prev=-1,curr=0,maxi=0;
        while(n){
            int d=n%2;
            n/=2;
            if(d==1){
                if(prev==-1) prev=curr;
                else{
                    maxi=max(maxi,curr-prev);
                    prev=curr;
                }
            }
            curr++;
        }
        return maxi;
    }
};