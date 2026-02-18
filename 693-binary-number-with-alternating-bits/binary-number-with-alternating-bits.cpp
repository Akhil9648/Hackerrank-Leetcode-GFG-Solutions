class Solution {
public:
    bool hasAlternatingBits(int n) {
        int flag=-1;
        while(n){
            if(n%2==0){
                if(flag==0) return false;
                flag=0;
            }
            else if(n%2==1){
                if(flag==1) return false;
                flag=1;
            }
            n/=2;
        }
        return true;
    }
};