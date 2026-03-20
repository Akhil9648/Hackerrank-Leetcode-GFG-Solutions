class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>ans(n-k+1,vector<int>(m-k+1));
        for(int i=0;i<=n-k;i++){
            for(int j=0;j<=m-k;j++){
                set<int>st;
                for(int u=i;u<i+k;u++){
                    for(int v=j;v<j+k;v++){
                        st.insert(grid[u][v]);
                    }
                }
                int mini=INT_MAX;
                int prev=-1e9;
                for(auto it:st){
                    mini=min(mini,it-prev);
                    prev=it;
                }
                if(st.size()==1) ans[i][j]=0;
                else ans[i][j]=mini;
            }
        }
        return ans;
    }
};