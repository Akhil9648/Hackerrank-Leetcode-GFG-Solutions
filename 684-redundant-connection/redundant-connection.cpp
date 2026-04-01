class DSU{
private:
    vector<int>parent,rank;
public:
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i = 0; i <= n; i++) parent[i] = i;
    }
    int findPar(int x){
        if(parent[x]!=x){
            parent[x]=findPar(parent[x]);
        }
        return parent[x];
    }
    void Union(int x,int y){
        int px=findPar(x);
        int py=findPar(y);
        if(px==py) return;
        if(rank[px]<rank[py]) parent[px]=py;
        else if(rank[py]<rank[px]) parent[py]=px;
        else{
            parent[px]=py;
            rank[py]++;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DSU DSU(n);
        for(auto it:edges){
            if(DSU.findPar(it[0])==DSU.findPar(it[1])) return {it[0],it[1]};
            DSU.Union(it[0],it[1]);
        }
        return {-1,-1};
    }
};