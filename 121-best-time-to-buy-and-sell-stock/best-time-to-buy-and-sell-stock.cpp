//Brute
class Solution1{
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int profit=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int curr=prices[j]-prices[i];
                profit=max(profit,curr);
            }
        }
        return profit;
    }
};
//Better
class Solution{
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mini=INT_MAX;
        int profit=0;
        for(int i=0;i<n;i++){
            mini=min(mini,prices[i]);
            int curr=prices[i]-mini;
            profit=max(profit,curr);
        }
        return profit;
    }
};