class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string a="";
        int i=0,sm=0;
        while(i<num){
            a+="9";
            sm+=9;
            i++;
        }
        if(sum>sm) return "";
        i=num-1;
        while(sum<sm){
            sm-=9;
            if(sum>=sm){
                int b=sum-sm;
                a[i]=(b+'0');
                return a;
            }
            a[i]='0';
            i--;
        }
        return a;
    }
};