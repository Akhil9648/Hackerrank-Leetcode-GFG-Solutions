class Solution {
public:
    int n;
    int getnext(vector<vector<int>>& data,int end){
        int r=n-1;
        int l=0;
        int result=n;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(data[mid][0]>=end){
                result=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return result;
    }
    int solve(vector<vector<int>>& data,int i,vector<int>& dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int next=getnext(data,data[i][1]);
        int take=data[i][2]+solve(data,next,dp);
        int nottake=solve(data,i+1,dp);
        return dp[i]=max(take,nottake);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n=profit.size();
        vector<vector<int>>data(n,vector<int>(3,0));
        for(int i=0;i<n;i++){
            data[i][0]=startTime[i];
            data[i][1]=endTime[i];
            data[i][2]=profit[i];
        }
        sort(data.begin(),data.end());
        vector<int>dp(n,-1);
        return solve(data,0,dp);
    }
};