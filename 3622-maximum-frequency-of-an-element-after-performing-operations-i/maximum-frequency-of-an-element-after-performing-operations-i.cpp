class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(begin(nums),end(nums));
        int n=nums.size();
        int a=*max_element(nums.begin(),nums.end());
        vector<int>cumsum(a+1,0);
        for(int i:nums) cumsum[i]++;
        for(int i=1;i<=a;i++){
            cumsum[i]+=cumsum[i-1];
        }
        int maxi=0;
        for(int t=0;t<=a;t++){
            if(cumsum[t]==0)  continue;
            int l=max(0,t-k);
            int r=min(a,t+k);
            int totalcnt=cumsum[r]-(l>0?cumsum[l-1]:0);
            int tgtcnt=cumsum[t]-(t>0?cumsum[t-1]:0);
            int need=totalcnt-tgtcnt;
            maxi=max(maxi,tgtcnt+min(need,numOperations));
        }
        return maxi;
    }
};