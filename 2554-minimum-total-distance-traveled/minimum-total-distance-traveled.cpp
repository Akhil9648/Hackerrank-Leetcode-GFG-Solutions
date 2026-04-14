class Solution {
public:
    int n,m;
    long long solve(int i,int j,vector<int>& robot,vector<int>& factory,vector<vector<long long>>& dp){
        if(i>=n) return 0;
        if(j>=m) return 1e18;
        if(dp[i][j]!=-1) return dp[i][j];
        long long take=abs(factory[j]-robot[i])+solve(i+1,j+1,robot,factory,dp);
        long long notTake=solve(i,j+1,robot,factory,dp);
        return dp[i][j]=min(take,notTake);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        vector<int>fac;
        for(auto it:factory){
            int i=0;
            while(i<it[1]){
                fac.push_back(it[0]);
                i++;
            }
        }
        sort(fac.begin(),fac.end());
        sort(robot.begin(),robot.end());
        m=fac.size();
        n=robot.size();
        vector<vector<long long>>dp(n,vector<long long>(m,-1));
        return solve(0,0,robot,fac,dp);
    }
};