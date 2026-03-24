class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int mul=1;
        int N=12345;
        long long prev=1,suf=1;
        vector<vector<int>>ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j]=prev%N;
                prev=(prev*grid[i][j]%N)%N;
            }
        }
        mul=1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                ans[i][j]=(ans[i][j]*suf%N)%N;
                suf=(suf*grid[i][j]%N)%N;
            }
        }
        return ans;
    }
};