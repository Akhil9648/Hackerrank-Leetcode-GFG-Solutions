class Solution {
public:
int N;
    vector<pair<int,int>>directions={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
    unordered_map<string,double>mp;
    double solve(int r,int c,int k){
        if(r<0 || r>=N || c<0 || c>=N) return 0;
        if(k==0) return 1;
        string curr=to_string(k)+"_"+to_string(r)+"_"+to_string(c);
        if(mp.find(curr)!=mp.end()) return mp[curr];
        double ans=0;
        for(auto &it:directions){
            int new_r=r+it.first;
            int new_c=c+it.second;
            ans+=(double)solve(new_r,new_c,k-1);
        }
        return mp[curr]=(double)ans/(8.0);
    }
    double knightProbability(int n, int k, int row, int column) {
        N=n;
        return solve(row,column,k);
    }
};