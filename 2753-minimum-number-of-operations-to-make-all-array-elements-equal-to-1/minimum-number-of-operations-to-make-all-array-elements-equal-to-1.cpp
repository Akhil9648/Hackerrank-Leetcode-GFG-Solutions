class Solution {
public:
    // int GCD(int a,int b){
    //     if(b==0) return a;
    //     return GCD(b,a%b);
    // }
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int cntG=0,cntZ=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                cntZ++;
            }
        }
        if(cntZ>0) return n-cntZ;
        int bestlen=INT_MAX;
        for(int i=0;i<n;i++){
            int g=nums[i];
            if(g==1){
                bestlen=1;
                break;
            }
            for(int j=i+1;j<n;j++){
                g=gcd(g,nums[j]);
                if(g==1){
                    bestlen=min(bestlen,j-i+1);
                    break;
                }
            }
        }
        if(bestlen==INT_MAX) return -1;
        return bestlen-1+(n-1);
    }
};