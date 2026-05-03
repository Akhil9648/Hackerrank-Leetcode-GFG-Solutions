class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
        while(n--){
            rotate(s.begin(), s.begin() + 1, s.end());
            if(s==goal) return true;
        }
        return false;
    }
};