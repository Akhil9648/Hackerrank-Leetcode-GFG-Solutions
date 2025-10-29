class Solution1 {
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
class Solution {
public:
    int smallestNumber(unsigned n) {
        return bit_ceil(n+1)-1;
    }
};