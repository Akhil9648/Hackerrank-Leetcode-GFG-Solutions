class Solution {
public:
    vector<vector<int>>directions={{1,0},{0,1},{-1,0},{0,-1}};
    void DFS(int i,int j,int prev,vector<vector<int>>& heights,vector<vector<bool>>& vis){
        if(i<0 || i>=heights.size() || j<0 || j>=heights[0].size() || vis[i][j] || heights[i][j]<prev){
            return;
        }
        vis[i][j]=true;
        for(auto &it:directions){
            DFS(i+it[0],j+it[1],heights[i][j],heights,vis);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<bool>>peci(n,vector<bool>(m,false));
        vector<vector<bool>>atlan(n,vector<bool>(m,false));
        for(int j=0;j<m;j++){
            DFS(0,j,INT_MIN,heights,peci);
            DFS(n-1,j,INT_MIN,heights,atlan);
        }
        for(int i=0;i<n;i++){
            DFS(i,0,INT_MIN,heights,peci);
            DFS(i,m-1,INT_MIN,heights,atlan);
        }
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(peci[i][j] && atlan[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
};