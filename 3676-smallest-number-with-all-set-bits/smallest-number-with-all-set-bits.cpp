class Solution {
public:
    int smallestNumber(int n) {
        int a=0;
        while(n){
            n/=2;
            a++;
        }
        return pow(2,a)-1;
    }
};