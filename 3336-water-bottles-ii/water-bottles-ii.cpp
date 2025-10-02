class Solution {
public:
    int maxBottlesDrunk(int n, int k) {
        int ans=0;
        while(n>0){
            if(n>=k){
                ans+=k;
                n-=k;
                k++;
                n++;
            }
            else{
                ans+=n;
                n=0;
            }
        }
        return ans;
    }
};