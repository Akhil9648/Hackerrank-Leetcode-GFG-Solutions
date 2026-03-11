class Solution {
public:
    int bitwiseComplement(int n) {
        int a=1;
        int k=n;
        while(k/=2){
            a++;
        }
        return pow(2,a)-n-1;
    }
};