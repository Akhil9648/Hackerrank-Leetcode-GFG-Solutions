class Solution1 {
public:
int n;
    int solve(int i,vector<int>& nums,int prev,int cnt,int flag,vector<vector<vector<vector<int>>>>& dp){
        if(i>=n){
            if(cnt==3) return 1;
            return 0;
        }
        if(cnt==3) return 1;
        if(dp[i][prev+1][flag+1][cnt]!=-1) return dp[i][prev+1][flag+1][cnt];
        if(prev==-1){
            int big=solve(i+1,nums,i,cnt+1,0,dp);
            int small=solve(i+1,nums,i,cnt+1,1,dp);
            int ignore=solve(i+1,nums,prev,cnt,flag,dp);
            return dp[i][prev+1][flag+1][cnt]=big+small+ignore;
        }
        if(flag){
            int take=0,notTake=0;
            if(nums[i]<nums[prev]){
                take=solve(i+1,nums,i,cnt+1,flag,dp);
            }
            notTake=solve(i+1,nums,prev,cnt,flag,dp);
            return dp[i][prev+1][flag+1][cnt]=take+notTake;
        }
        else{
            int take=0,notTake=0;
            if(nums[i]>nums[prev]){
                take=solve(i+1,nums,i,cnt+1,flag,dp);
            }
            notTake=solve(i+1,nums,prev,cnt,flag,dp);
            return dp[i][prev+1][flag+1][cnt]=take+notTake;
        }
        return 0;
    }
    int numTeams(vector<int>& rating) {
        n=rating.size();
        vector<vector<vector<vector<int>>>>dp(n,vector<vector<vector<int>>>(n+1,vector<vector<int>>(4,vector<int>(4,-1))));
        return solve(0,rating,-1,0,-1,dp);
    }
};
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n=rating.size();
        vector<int>gr(n,0),le(n,0);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(rating[j]>rating[i]) gr[i]++;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(rating[j]<rating[i]) le[i]++;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int leftSmaller = le[i];
            int rightGreater = gr[i];
            int leftGreater = i - le[i];
            int rightSmaller = (n-i-1) - gr[i];
            ans += leftSmaller * rightGreater;
            ans += leftGreater * rightSmaller;
        }
        return ans;
    }
};
