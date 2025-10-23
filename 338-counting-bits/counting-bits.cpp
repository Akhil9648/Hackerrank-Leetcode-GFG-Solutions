class Solution {
public:
    int find(int n){
        int cnt=0;
        while(n){
            int a=n%2;
            n/=2;
            if(a==1) cnt++;
        }
        return cnt;
    }
    vector<int> countBits(int n) {
        vector<int>arr(n+1,0);
        for(int i=1;i<=n;i++){
            arr[i]=find(i);
        }
        return arr;
    }
};