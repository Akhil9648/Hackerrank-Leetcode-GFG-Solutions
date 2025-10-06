class Solution {
public:
    vector<vector<int>>direction={{0,1},{0,-1},{1,0},{-1,0}};
    bool possible(int i,int j,int mid,vector<vector<int>>& grid,vector<vector<bool>>& vis){
        int n=grid.size();
        if(i<0 || i>=n || j<0 || j>=n || vis[i][j] || grid[i][j]>mid) return false;
        vis[i][j]=true;
        if(i==n-1 && j==n-1) return true;
        for(auto & dir:direction){
            if(possible(i+dir[0],j+dir[1],mid,grid,vis)) return true;
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int l=grid[0][0];
        int r=n*n-1;
        int result=0;
        while(l<=r){
            int mid=(l+r)/2;
            vector<vector<bool>>vis(n,vector<bool>(n,false));
            if(possible(0,0,mid,grid,vis)){
                r=mid-1;
                result=mid;
            }
            else{
                l=mid+1;
            }
        }
        return result;
    }
};