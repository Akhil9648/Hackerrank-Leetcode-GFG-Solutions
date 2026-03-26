class Solution {
public:
    typedef long long ll;
    bool checkhor(vector<vector<int>>& grid,ll sum){
        ll curr=0;
        int n=grid.size();
        int m=grid[0].size();
        unordered_set<ll>st;
        for(int i=0;i<=n-2;i++){
            for(int j=0;j<m;j++){
                curr+=grid[i][j];
                st.insert(grid[i][j]);
            }
            ll bottom=sum-curr;
            ll diff=curr-bottom;
            if(diff==0) return true;
            if(diff==(ll)grid[0][0]) return 1;
            if(diff==(ll)grid[0][m-1]) return 1;
            if(diff==(ll)grid[i][0]) return true;
            if(i>0 && m>1 && st.count(diff)) return true;
        }
        return false;
    }
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        ll sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum+=grid[i][j];
            }
        }
        if(checkhor(grid,sum)) return true;
        reverse(grid.begin(),grid.end());
        if(checkhor(grid,sum)) return true;
        reverse(grid.begin(),grid.end());
        vector<vector<int>>transpose(m,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                transpose[j][i]=grid[i][j];
            }
        }
        if(checkhor(transpose,sum)) return true;
        reverse(transpose.begin(),transpose.end());
        if(checkhor(transpose,sum)) return true;
        return 0;
    }
};