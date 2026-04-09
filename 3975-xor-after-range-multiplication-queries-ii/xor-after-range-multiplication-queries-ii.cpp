class Solution1 {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>vis(n,0);
        int MOD=1e9+7;
        int ans=0;
        for(auto &it:queries){
            int l=it[0];
            int r=it[1];
            int k=it[2];
            int v=it[3];
            for(int i=l;i<=r;i+=k){
                if(vis[i]==1){
                    ans^=nums[i];
                }
                nums[i]=(1LL*nums[i]*v)%(MOD);
                ans^=nums[i];
                vis[i]=1;
            }
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0) ans^=nums[i];
        }
        return ans;
    }
};
class Solution {
public:
    int MOD=1e9+7;
    long long power(long long a,long long b){
        if(b==0) return 1;
        long long half=power(a,b/2);
        long long result=(half*half)%MOD;
        if(b%2){
            result=(result*a)%MOD;
        }
        return result;
    }
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int blockSize=ceil(sqrt(n));
        unordered_map<int,vector<vector<int>>>smallKMap;
        for(auto &query:queries){
            int L=query[0];
            int R=query[1];
            int K=query[2];
            int V=query[3];
            if(K>=blockSize){
                for(int i=L;i<=R;i+=K){
                    nums[i]=(1LL*nums[i]*V)%MOD;
                }
            } else {
                smallKMap[K].push_back(query);
            }
        }
        for(auto& [K, allQueries] : smallKMap) {
            vector<long long> diff(n, 1);

            for(auto& query : allQueries) {
                int L = query[0];
                int R = query[1];
                int V = query[3];

                diff[L] = (diff[L] * V) % MOD;

                int steps = (R - L)/K;
                int next  = L + (steps+1)*K;

                if(next < n)
                    diff[next] = (diff[next] * power(V, MOD-2)) % MOD;
            }

            //Cumulative product
            for(int i = 0; i < n; i++) {
                if(i-K >= 0)
                    diff[i] = (diff[i] * diff[i-K]) % MOD;
            }

            //Apply diff to nums
            for(int i = 0; i < n; i++) {
                nums[i] = (1LL * nums[i] * diff[i]) % MOD;
            }
        }

        int result = 0;
        for(int &num : nums) {
            result = (result ^ num);
        }

        return result;
    }
};