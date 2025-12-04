class Solution {
public:
    int countCollisions(string s) {
        int n = s.size();
        
        int i = 0;
        while (i < n && s[i] == 'L') i++;
        
        int j = n - 1;
        while (j >= 0 && s[j] == 'R') j--;
        
        int ans = 0;
        for (int k = i; k <= j; k++) {
            if (s[k] != 'S') ans++;
        }
        
        return ans;
    }
};
