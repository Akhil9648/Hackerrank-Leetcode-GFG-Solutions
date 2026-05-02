class Solution {
public:
    bool find(int n){
        int flag=0;
        while(n){
            int d=n%10;
            n/=10;
            if(d==2 || d==5 || d==6 || d==9) flag=1;
            if(d==3 || d==4 || d==7) return false;
        }
        return flag;
    }
    int rotatedDigits(int n) {
        int cnt=0;
        for(int i=2;i<=n;i++){
            if(find(i)) cnt++;
        }
        return cnt;
    }
};