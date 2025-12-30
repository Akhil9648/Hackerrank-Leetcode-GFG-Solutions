class Solution {
public:
    bool isMagicSquare(vector<vector<int>>& grid, int r, int c) {
        int sum = grid[r][c] + grid[r][c+1] + grid[r][c+2];
        unordered_set<int> st;

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                int num = grid[r+i][c+j];
                if(num < 1 || num > 9 || st.count(num)) return false;
                st.insert(num);
            }
        }

        for(int i = 0; i < 3; i++) {
            if(grid[r][c+i] + grid[r+1][c+i] + grid[r+2][c+i] != sum) return false;
            if(grid[r+i][c] + grid[r+i][c+1] + grid[r+i][c+2] != sum) return false;
        }

        if(grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2] != sum) return false;
        if(grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c] != sum) return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int cnt = 0;

        for(int i = 0; i <= m - 3; i++) {
            for(int j = 0; j <= n - 3; j++) {
                if(isMagicSquare(grid, i, j)) cnt++;
            }
        }
        return cnt;
    }
};