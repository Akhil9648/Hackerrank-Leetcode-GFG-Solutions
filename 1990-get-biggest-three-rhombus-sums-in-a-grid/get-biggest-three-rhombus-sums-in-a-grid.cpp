class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        set<int>st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                st.insert(grid[i][j]);
                if(st.size()>3) st.erase(begin(st));
                for(int side=1;i-side>=0 && i+side<n && j-side>=0 && j+side<m;side++){
                    int sum=0;
                    for(int k=0;k<side;k++){
                        sum+=grid[i-side+k][j+k];
                        sum+=grid[i+side-k][j-k];
                        sum+=grid[i+k][j+side-k];
                        sum+=grid[i-k][j-side+k];
                    }
                    st.insert(sum);
                    if(st.size()>3) st.erase(begin(st));
                }
            }
        }
        return vector<int>(rbegin(st),rend(st));
    }
};