class Solution1 {
public:
    int maxi=0,n;
    void solve(int i,vector<int>& nums,vector<int>& curr){
        if(i>=n){
            unordered_set<int>e,o;
            for(int i:curr){
                if(i%2==0) e.insert(i);
                else o.insert(i);
            }
            if(e.size()==o.size()){
                if(maxi<curr.size()) maxi=curr.size();
            }
            return ;
        }
        curr.push_back(nums[i]);
        solve(i+1,nums,curr);
        curr.pop_back();
        if(curr.size()==0){
        solve(i+1,nums,curr);
        }
        solve(n,nums,curr);
        return ;
    }
    int longestBalanced(vector<int>& nums) {
        n=nums.size();
        vector<int>curr;
         solve(0,nums,curr);
         return maxi;
    }
};
class Solution2 {
public:
    int n;
    bool check(int i,int j,vector<int>& nums){
        unordered_set<int>e,o;
        for(int u=i;u<=j;u++){
            if(nums[u]%2==0) e.insert(nums[u]);
            else o.insert(nums[u]);
        }
        return (e.size()==o.size());
    }
    int solve(int i,int j,vector<int>& nums,vector<vector<int>>& dp){
        if(j>=n-1){
            if(check(i,j,nums)) return j-i+1;
            return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int take=0,notTake=0;
        take=solve(i,j+1,nums,dp);
        if(j-i==0){
            notTake=solve(i+1,j+1,nums,dp);
        }
        else{
            if(check(i,j,nums)) notTake=j-i+1;
        }
        return dp[i][j]=max(take,notTake);
    }
    int longestBalanced(vector<int>& nums) {
        n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(0,0,nums,dp);
    }
};
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            unordered_set<int>eve,odd;
            for(int j=i;j<n;j++){
                if(nums[j]%2==0){
                    eve.insert(nums[j]);
                }
                else{
                    odd.insert(nums[j]);
                }
                if(eve.size()==odd.size()){
                    maxi=max(maxi,j-i+1);
                }
            }
        }
        return maxi;
    }
};