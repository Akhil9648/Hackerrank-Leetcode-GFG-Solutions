class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(n);
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int>inor(n,0);
        for(int i=0;i<n;i++){
            for(int it:adj[i]){
                inor[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(inor[i]==0) q.push(i);
        }
        vector<int>topo;
        while(!q.empty()){
            int a=q.front();
            q.pop();
            topo.push_back(a);
            for(int it:adj[a]){
                inor[it]--;
                if(inor[it]==0) q.push(it);
            }
        }
        if(topo.size()==n) return topo;
        return {};
    }   
};