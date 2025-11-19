class Solution {
public:
    int dr[4]={0,1,0,-1};
    int dc[4]={1,0,-1,0};
    void dfs(int i,int j,int prev,vector<vector<int>> &heights,vector<vector<int>>& vis){
        if(i<0 || i>=heights.size() || j<0 || j>=heights[0].size() || vis[i][j] || heights[i][j]<prev) return;
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            dfs(i+dr[k],j+dc[k],heights[i][j],heights,vis);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>peci(n,vector<int>(m,0)),atl(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            dfs(i,0,INT_MIN,heights,peci);
            dfs(i,m-1,INT_MIN,heights,atl);
        }
        for(int j=0;j<m;j++){
            dfs(0,j,INT_MIN,heights,peci);
            dfs(n-1,j,INT_MIN,heights,atl);
        }
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(peci[i][j] && atl[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
};