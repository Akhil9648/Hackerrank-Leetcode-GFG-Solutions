class Solution {
public:
    int count=0;
    void solve(int i,int n,vector<bool>curr){
        if(i>n){
            count++;
        }
        for(int j=1;j<=n;j++){
            if(!curr[j] && (i%j==0 || j%i==0)){
            curr[j]=true;
            solve(i+1,n,curr);
            curr[j]=false;
            }
        }
    }
    int countArrangement(int n) {
        vector<bool>curr(n+1,false);
        solve(1,n,curr);
        return count;
    }
};