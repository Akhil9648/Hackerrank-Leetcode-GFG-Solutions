class Solution {
public:
    int findClosest(int x, int y, int z) {
        int a=abs(z-x);
        int b=abs(z-y);
        if(a>b) return 2;
        else if(b>a) return 1;
        return 0;
    }
};