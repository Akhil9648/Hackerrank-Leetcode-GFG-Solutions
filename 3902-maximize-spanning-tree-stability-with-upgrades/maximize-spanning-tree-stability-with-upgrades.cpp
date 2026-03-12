class DSU{
public:
    vector<int>parent,rank;
    DSU(int n){
        parent.resize(n);
        rank.resize(n,1);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int find(int x){
        if(x==parent[x]) return x;
        return parent[x]=find(parent[x]);
    }
    bool unite(int x,int y){
        int x_p=find(x);
        int y_p=find(y);
        if(x_p==y_p) return false;
        if(rank[x_p]>rank[y_p]) parent[y_p]=x_p;
        else if(rank[x_p]<rank[y_p]) parent[x_p]=y_p;
        else{
            parent[x_p]=y_p;
            rank[y_p]++;
        }
        return true;
    }
};
class Solution {
public:
    bool check(vector<vector<int>>& edges,int mid,int n,int k){
        vector<vector<int>>arr;
        DSU dsu(n);
        for(auto it:edges){
            if(it[3]==1){
                if(it[2] < mid) return false;
                else{
                    dsu.unite(it[0],it[1]);
                }
            }
            else if(it[3]==0){
                if(it[2]>=mid){
                    dsu.unite(it[0],it[1]);
                }
                else if(it[2]*2>=mid){
                    arr.push_back(it);
                }
            }
        }
        sort(arr.begin(), arr.end(), [](auto &a, auto &b){
            return a[2] > b[2];
});
    for(auto &it:arr){
        if(dsu.find(it[0])!=dsu.find(it[1])){
            if(k<=0) return false;
            dsu.unite(it[0],it[1]);
            k--;
        }
    }
        int a=dsu.find(0);
        for(int i=1;i<n;i++){
            if(dsu.find(i)!=a) return false;
        }
        return true;
    }
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int low=0,high=2*1e5;
        int ans=-1;
        DSU dsu(n);
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int s = edge[2];
            int m = edge[3];

            if (m == 1) { 
                if(dsu.unite(u, v) == false)
                    return -1;
            }
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(edges,mid,n,k)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};