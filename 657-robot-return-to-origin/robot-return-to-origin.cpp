class Solution {
public:
    bool judgeCircle(string moves) {
        int h=0,r=0;
        for(auto it:moves){
            if(it=='U') h++;
            else if(it=='D') h--;
            else if(it=='L') r++;
            else r--;
        }
        return (h==0 && r==0);
    }
};