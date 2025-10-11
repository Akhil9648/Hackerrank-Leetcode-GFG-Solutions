class DisjointSet{
    public:
    vector<int>parent,size,rank;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++) parent[i]=i; 
    }
    int findUpar(int u){
        if(u==parent[u]) return u;
        return parent[u]=findUpar(parent[u]);
    }
    void uniteByRank(int u,int v){
        int pu=findUpar(u);
        int pv=findUpar(v);
        if(pu==pv) return;
        if(rank[pu]<rank[pv]) parent[pu]=pv;
        else if(rank[pv]<rank[pu]) parent[pv]=pu;
        else{
            parent[pv]=pu;
            rank[pu]++;
        }
    }
    void uniteBySize(int u,int v){
        int pu=findUpar(u);
        int pv=findUpar(v);
        if(pu==pv) return;
        if(size[pu]<size[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else{
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mp.find(mail)==mp.end()){
                    mp[mail]=i;
                }
                else{
                    ds.uniteBySize(mp[mail],i);
                }
            }
        }
        vector<vector<string>>merged(n);
        for(auto it:mp){
            string mail=it.first;
            int node=ds.findUpar(it.second);
            merged[node].push_back(mail);
        }
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(merged[i].size()==0) continue;
            sort(merged[i].begin(),merged[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it:merged[i]) temp.push_back(it);
            ans.push_back(temp);
        }
        return ans;
    }
};