class DisjointSet {
public:
    vector<int> parent, rank, size;

    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1); // initialize size
        for (int i = 0; i <= n; i++) parent[i] = i;
    }

    int findUpar(int u) {
        if (u == parent[u]) return u;
        return parent[u] = findUpar(parent[u]);
    }

    void uniteByRank(int u, int v) {
        int pu = findUpar(u);
        int pv = findUpar(v);
        if (pu == pv) return;

        if (rank[pu] < rank[pv]) parent[pu] = pv;
        else if (rank[pv] < rank[pu]) parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    void uniteBySize(int u, int v) {
        int pu = findUpar(u);
        int pv = findUpar(v);
        if (pu == pv) return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
class Solution {
private:
bool isvalid(int nr,int nc,int n){
    if(nr>=0 && nr<n && nc>=0 && nc<n) return true;
    return false;
}
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;
                int dc[]={1,0,-1,0};
                int dr[]={0,-1,0,1};
                for(int k=0;k<4;k++){
                    int nr=i+dr[k];
                    int nc=dc[k]+j;
                    if(isvalid(nr,nc,n) && grid[nr][nc]==1){
                        int node=i*n+j;
                        int adj=nr*n+nc;
                        ds.uniteBySize(node,adj);
                    }
                }
            }
        }
        int mx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) continue;
                int dc[]={1,0,-1,0};
                int dr[]={0,-1,0,1};
                set<int>comp;
                for(int k=0;k<4;k++){
                    int nr=i+dr[k];
                    int nc=dc[k]+j;
                    if(isvalid(nr,nc,n) && grid[nr][nc]==1){
                        comp.insert(ds.findUpar(nr*n+nc));
                    }
                }
                int st=1;
                for(auto it:comp){
                    st+=ds.size[it];
                }
                mx=max(mx,st);
            }
        }
        for(int i=0;i<n*n;i++){
            mx=max(mx,ds.size[ds.findUpar(i)]);
        }
        return mx;
    }
};