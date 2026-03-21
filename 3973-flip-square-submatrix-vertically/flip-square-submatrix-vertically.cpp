class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int u=k;
        vector<vector<int>>ans=grid;
        for(int i=x;i<x+k;i++){
            for(int j=y;j<y+k;j++){
                ans[i][j]=grid[i+u-k+u-1][j];
                ans[i+u-k+u-1][j]=grid[i][j];
            }
            u--;
        }
        return ans;
    }
};