class Solution {
public:
    int totalMoney(int n) {
        int u=1;
        int b=1,sum=0,a=u;
        while(b<=n){
            a=u;
            while(b%7!=0){
                sum+=a;
                a++;
                b++;
                if(b%7==0 && b<=n) sum+=a;
                if(b>n) return sum;
            }
            b++;
            u++;
            a=u;
        }
        return sum;
    }
};