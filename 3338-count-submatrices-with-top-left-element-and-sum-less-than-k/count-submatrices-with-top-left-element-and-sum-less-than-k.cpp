class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>rsum(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i>0){
                    rsum[i][j]=rsum[i-1][j]+grid[i][j];
                }
                else{
                    rsum[i][j]=grid[i][j];
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=0;j<m;j++){
                sum+=rsum[i][j];
                if(sum>k) break;
                count++;
            }
            cout<<endl;
        }
        return count;
    }
};