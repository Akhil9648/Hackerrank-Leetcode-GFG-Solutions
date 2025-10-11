class Solution1 {
public:
    void dfs(int i,vector<int>&vis,vector<vector<int>>& isConnected){
        vis[i]=1;
        for(int it:isConnected[i]){
            if(!vis[it]){
                dfs(it,vis,isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size(),count=0;
        vector<int>vis(n+1,0);
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                dfs(i,vis,adj);
            }
        }
        return count;
    }
};
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
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if (isConnected[i][j] && i != j) {
                    ds.uniteBySize(i, j);
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(ds.findUpar(i)==i) count++;
        }
        return count;
    }
};