class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int a=0,b=0;
        for(char c:s){
            if(c=='a') a++;
            else b++;
        }
        return abs(a-b);
    }
};