// Approach-1 Memoization
class Solution1 {
public:
int n,maxi=0;
    int solve(int i,int prev,vector<int>& arr,int diff,vector<vector<int>>& dp){
        if(i>=n) return 0;
        int maxi=0;
        int take=0;
        if(dp[i][prev]!=-1) return dp[i][prev];
        if(arr[i]-prev==diff){
        take=1+solve(i+1,arr[i],arr,diff,dp);
        }
        int notTake=solve(i+1,prev,arr,diff,dp);
        return dp[i][prev]=max(take,notTake);
    }
    int longestSubsequence(vector<int>& arr, int difference) {
        n=arr.size();
        int maxi=0;
        int u=*max_element(arr.begin(),arr.end());
        vector<vector<int>>dp(n,vector<int>(u+1,-1));
        for(int i=0;i<n;i++){
            maxi=max(maxi,1+solve(i+1,arr[i],arr,difference,dp));
        }
        return maxi;
    }
};
// Approach-2 Tabulation
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n=arr.size();
        vector<int>dp(n,0);
        unordered_map<int,int>valuetillnow;
        // Initialiing a frequency map to store the values of each index of the array
        int maxi=0;
        dp[0]=1;
        for(int i=n-1;i>=0;i--){
            int nextelement=arr[i]+difference;
            int len=1;
            if(valuetillnow.find(nextelement)!=valuetillnow.end()){
                len=1+valuetillnow[nextelement]; //Checking the length of each element
            }
            dp[i]=len;
            valuetillnow[arr[i]]=len;
            maxi=max(maxi,len); //taking maximum length from the pool of valid length
        }
        return maxi;
    }
};
