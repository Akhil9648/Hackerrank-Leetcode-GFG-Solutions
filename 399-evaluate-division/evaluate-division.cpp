class Solution {
public:
    void dfs(string i,string des,unordered_map<string,vector<pair<string,double>>>& adj,unordered_set<string>& vis,double prod,double &ans){
        vis.insert(i);
        if(i==des){
            ans=prod;
            return;
        }
        for(auto it:adj[i]){
            string b=it.first;
            double val=it.second;
            if(vis.find(b)==vis.end()){
                dfs(b,des,adj,vis,prod*val,ans);
            }
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>>adj;
        int n=equations.size();
        for(int i=0;i<n;i++){
            string a=equations[i][0];
            string b=equations[i][1];
            double val=values[i];
            adj[a].push_back({b,val});
            adj[b].push_back({a,1.0/val});
        }
        vector<double>ans;
        for(auto it:queries){
            string a=it[0];
            string b=it[1];
            double prod=1.0,an=-1.0;
            if(adj.find(a)!=adj.end()){
                unordered_set<string>vis;
                dfs(a,b,adj,vis,prod,an);
            }
            ans.push_back(an);
        }
        return ans;
    }
};