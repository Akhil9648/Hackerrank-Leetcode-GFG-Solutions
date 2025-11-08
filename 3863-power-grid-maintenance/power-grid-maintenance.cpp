// Approach-1 DFS O(n*(V+E))
class Solution1 {
public:
    void dfs(int i,int p,unordered_map<int, vector<int>>& adj,vector<int>& vis,vector<int>& comp,unordered_map<int,set<int>>&mp){
        vis[i]=1;
        comp[i]=p;
        mp[p].insert(i);
        for(auto &it:adj[i]){
            if(!vis[it]){
                dfs(it,p,adj,vis,comp,mp);
            }
        }
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        for(auto &it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        unordered_map<int,set<int>>mp;
        vector<int>vis(c+1,0),comp(c+1,-1);
        for(int i=1;i<=c;i++){
            if(!vis[i]){
                dfs(i,i,adj,vis,comp,mp);
            }
        }
        vector<int>ans;
        for(auto it : queries){
            int a = it[0];
            int b = it[1];
            int d = comp[b];
            if(a == 1){
                if(mp[d].count(b)) ans.push_back(b);
                else if(!mp[d].empty()) ans.push_back(*mp[d].begin());
                else ans.push_back(-1);
            }
            else{
                mp[d].erase(b);
            }
        } 

        return ans;
    }
};
// Approach-2 BFS O(n*(V+E))
class Solution2 {
public:
    void bfs(int i,int p,unordered_map<int, vector<int>>& adj,vector<int>& vis,vector<int>& comp,unordered_map<int,set<int>>&mp){
        queue<int>q;
        q.push(i);
        vis[i]=1;
        comp[i]=p;
        mp[p].insert(i);
        while(!q.empty()){
            int a=q.front();
            q.pop();
            for(int it:adj[a]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                    comp[it]=p;
                    mp[p].insert(it);
                }
            }
        }
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        for(auto &it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        unordered_map<int,set<int>>mp;
        vector<int>vis(c+1,0),comp(c+1,-1);
        for(int i=1;i<=c;i++){
            if(!vis[i]){
                bfs(i,i,adj,vis,comp,mp);
            }
        }
        vector<int>ans;
        for(auto it : queries){
            int a = it[0];
            int b = it[1];
            int d = comp[b];
            if(a == 1){
                if(mp[d].count(b)) ans.push_back(b);
                else if(!mp[d].empty()) ans.push_back(*mp[d].begin());
                else ans.push_back(-1);
            }
            else{
                mp[d].erase(b);
            }
        } 

        return ans;
    }
};
// Approach-3
// Optimal Approach DSU 
class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int Find(int x){
        if(x==parent[x]) return x;
        return parent[x]=Find(parent[x]);
    }
    void Union(int x,int y){
        int xp=Find(x);
        int yp=Find(y);
        if(xp==yp) return;
        if(rank[xp]<rank[yp]){
            parent[xp]=yp;
            rank[yp]++;
        }
        else{
            parent[yp]=xp;
            rank[xp]++;
        }
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        rank.resize(c+1,0);
        parent.resize(c+1,0);
        for(int i=1;i<=c;i++){
            parent[i]=i;
        }
        for(auto &edge:connections){
            Union(edge[0],edge[1]);
        }
        unordered_map<int,set<int>>mp;
        vector<int>comp(c+1,-1);
        for(int i=1;i<=c;i++){
            int par=Find(i);
            comp[i]=par;
            mp[par].insert(i);
        }
        vector<int>ans;
        for(auto &it:queries){
            int a=it[0];
            int b=it[1];
            int d=comp[b];
            if(a==1){
                if(mp[d].count(b)) ans.push_back(b);
                else if(!mp[d].empty()) ans.push_back(*mp[d].begin());
                else ans.push_back(-1);
            }
            else{
                mp[d].erase(b);
            }
        }
        return ans;
    }
};
