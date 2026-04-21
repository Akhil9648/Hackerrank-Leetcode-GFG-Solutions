class Solution {
    vector<int>parent;
    int find(int x){
        if(x!=parent[x]){
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }
    void unite(int x,int y){
        parent[find(x)]=find(y);
    }
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n=source.size();
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
        for (auto &e : allowedSwaps)
            unite(e[0], e[1]);
        unordered_map<int, unordered_map<int, int>> mp;
        for (int i = 0; i < n; i++) mp[find(i)][source[i]]++;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int p = find(i);
            if (mp[p][target[i]] > 0) {
                mp[p][target[i]]--;
            } else {
                ans++;
            }
        }
        return ans;
    }
};