class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxi=0,mini=INT_MAX;
        int maxp=0;
        for(int i=0;i<n;i++){
            if(prices[i]<mini){
                mini=prices[i];
                maxi=0;
            }
            maxi=max(maxi,prices[i]);
            maxp=max(maxp,(maxi-mini));
        }
        return maxp;
    }
};