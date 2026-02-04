class Solution1 {
public:
    bool isTrionic(int u,int j,vector<int>& nums) {
        int n=j;
        int i=u;
        while(i<n-1 && nums[i]<nums[i+1]){
            i++;
        }
        if(i==u) return false;
        int peak=i;
        while(i<n-1 && nums[i]>nums[i+1]){
            i++;
        }
        if(i==peak || i==n-1) return false;
        int valley=i;
        while(i<n-1 && nums[i]<nums[i+1]) i++;
        return (i>valley && i==n-1);
    }
    long long solve(int i,int j,vector<int>& nums,vector<long long>& pref,vector<vector<long long>>& dp){
        int n=nums.size();
        if(i>=n || j>=n || (j-i+1)<4) return LLONG_MIN;
        if(dp[i][j]!=LLONG_MIN) return dp[i][j];
        long long take=LLONG_MIN,travi=LLONG_MIN,travj=LLONG_MIN;
        if(isTrionic(i,j+1,nums)){
            take=pref[j+1]-pref[i];
        }
        if(j-i+1>4){
            travi=solve(i+1,j,nums,pref,dp);
        }
        travj=solve(i,j+1,nums,pref,dp);
        return dp[i][j]=max(take,max(travi,travj));
    }
    long long maxSumTrionic(vector<int>& nums) {
        int n=nums.size();
        vector<long long> pref(n+1,0);
        for(int i=0;i<n;i++){
            pref[i+1] = pref[i] + nums[i];
        }
        vector<vector<long long>>dp(n,vector<long long>(n,LLONG_MIN));
        return solve(0,3,nums,pref,dp);
    }
};
class Solution {
public:
    typedef long long ll;
    int n;
    vector<vector<ll>> memo;

    ll solve(int i, int trend, vector<int>& nums) {
        if(i == n) {
            if(trend == 3) {
                return 0; //no more elements, you reached out of bound
            } else {
                return LLONG_MIN/2; //invalid small value
            }
        }

        if(memo[i][trend] != LLONG_MIN) {
            return memo[i][trend];
        }

        ll take = LLONG_MIN/2;
        ll skip = LLONG_MIN/2;

        //skip
        if(trend == 0) {
            skip = solve(i+1, 0, nums);
        }

        //i am at trend 3 and i can now end at nums[i]
        if(trend == 3) {
            take = nums[i]; //finish it here
        }

        if(i+1 < n) {
            int curr = nums[i];
            int next = nums[i+1];

            if(trend == 0 && next > curr) {
                take = max(take, curr + solve(i+1, 1, nums));
            } else if(trend == 1) {
                if(next > curr) {
                    take = max(take, curr + solve(i+1, 1, nums));
                } else if(next < curr) {
                    take = max(take, curr + solve(i+1, 2, nums));
                }
            } else if(trend == 2) {
                if(next < curr) {
                    take = max(take, curr + solve(i+1, 2, nums));
                } else if(next > curr) {
                    take = max(take, curr + solve(i+1, 3, nums));
                }
            } else if(trend == 3 && next > curr) {
                take = max(take, curr + solve(i+1, 3, nums));
            }
        }
        
        return memo[i][trend] = max(take, skip);
    }

    ll maxSumTrionic(vector<int>& nums) {
        n = nums.size();

        memo.assign(n+1, vector<ll>(4, LLONG_MIN));

        return solve(0, 0, nums); //solve(i, trend = 0)
    }
};
