class Solution {
public:
    int trap(vector<int>& arr) {
       stack<int>st;
       int n=arr.size();
       vector<int>NGE(n),PGE(n);
       int maxi=0;
       for(int i=0;i<n;i++){
            maxi=max(maxi,arr[i]);
            PGE[i]=maxi;
       }
       maxi=0;
       for(int i=n-1;i>=0;i--){
            maxi=max(maxi,arr[i]);
            NGE[i]=maxi;
       }
       int sum=0;
       for(int i=0;i<n;i++){
            int a=min(PGE[i],NGE[i]);
            sum+=(a-arr[i]);
       }
       return sum;
    }
};