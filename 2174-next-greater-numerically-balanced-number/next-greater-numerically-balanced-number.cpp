class Solution {
public:
    bool isbalanced(int n){
        vector<int>cnt(10,0);
        while(n){
            int d=n%10;
            cnt[d]++;
            n/=10;
        }
        for(int i=0;i<10;i++){
            if(cnt[i]!=0 && cnt[i]!=i) return false;
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        int maxi=1224444;
        for(int i=n+1;i<=maxi;i++){
            if(isbalanced(i)) return i;
        }
        return -1;
    }
};