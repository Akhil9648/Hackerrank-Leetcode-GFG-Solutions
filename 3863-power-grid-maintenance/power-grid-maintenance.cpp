class Solution {
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