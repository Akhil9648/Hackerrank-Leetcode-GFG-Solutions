class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;

        vector<vector<int>> curr(n, vector<int>(m, 0));
        vector<vector<int>> cntX(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 'X') curr[i][j] = 1;
                else if(grid[i][j] == 'Y') curr[i][j] = -1;
                if(grid[i][j] == 'X') cntX[i][j] = 1;
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i > 0){
                    curr[i][j] += curr[i-1][j];
                    cntX[i][j] += cntX[i-1][j];
                }
                if(j > 0){
                    curr[i][j] += curr[i][j-1];
                    cntX[i][j] += cntX[i][j-1];
                }
                if(i > 0 && j > 0){
                    curr[i][j] -= curr[i-1][j-1];
                    cntX[i][j] -= cntX[i-1][j-1];
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(curr[i][j] == 0 && cntX[i][j] > 0){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};