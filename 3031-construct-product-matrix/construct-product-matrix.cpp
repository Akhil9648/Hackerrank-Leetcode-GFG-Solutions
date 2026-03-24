class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int mul=1;
        vector<vector<int>>prevmul(n,vector<int>(m,0));
        vector<vector<int>>nextmul(n,vector<int>(m,0));
        vector<vector<int>>ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                prevmul[i][j]=mul;
                mul*=(grid[i][j])%12345;
                mul%=12345;
            }
        }
        mul=1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                nextmul[i][j]=mul;
                mul*=(grid[i][j])%12345;
                mul%=12345;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j]=(prevmul[i][j]*nextmul[i][j])%12345;
            }
        }
        return ans;
    }
};