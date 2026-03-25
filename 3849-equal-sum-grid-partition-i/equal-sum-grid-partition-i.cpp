class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<long long>>rsum(n,vector<long long>(m,0));
        long long sum=0;
        for(int i=0;i<n;i++){
            rsum[i][0]=grid[i][0];
            for(int j=1;j<m;j++){
                rsum[i][j]=(rsum[i][j-1]+grid[i][j]);
            }
            sum+=rsum[i][m-1];
        }
        long long curr=0;
        for(int i=0;i<n;i++){
            curr+=rsum[i][m-1];
            if(2*curr==sum) return true;
        }
        vector<vector<long long>>csum(n,vector<long long>(m,0));
        sum=0,curr=0;
        for(int j=0;j<m;j++){
            csum[0][j]=grid[0][j];
            for(int i=1;i<n;i++){
                csum[i][j]=(csum[i-1][j]+grid[i][j]);
            }
            sum+=csum[n-1][j];
        }
        for(int j=0;j<m;j++){
            curr+=csum[n-1][j];
            if(2*curr==sum) return true;
        }
        return false;
    }
};