class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        int m=queries.size();
        vector<int>ans;
        for(int i=0;i<m;i++){
            int a=nums[queries[i]];
            int b=queries[i];
            auto &vec = mp[a];
            int sz=vec.size();
            if(vec.size()>1){
                int res=INT_MAX;
                int pos=lower_bound(vec.begin(),vec.end(),b)-vec.begin();
                int right=vec[(pos+1)%sz];
                int d=abs(b-right);
                int qw=n-d;
                res=min({res,d,qw});
                int left=vec[(pos-1+sz)%sz];
                d=abs(b-left);
                qw=n-d;
                res=min({res,d,qw});
                ans.push_back(res);
            }
            else ans.push_back(-1);
        }
        return ans;
    }
};