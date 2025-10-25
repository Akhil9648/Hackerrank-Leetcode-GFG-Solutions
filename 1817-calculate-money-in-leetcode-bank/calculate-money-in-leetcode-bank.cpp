class Solution1 {
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
class Solution {
public:
    int totalMoney(int n) {
        int w=n/7;
        int d=n%7;
        int sum=7*(w*(w+1)/2+3*w);
        sum+=(d*(2*(w+1)+(d-1))/2);
        return sum;
    }
};