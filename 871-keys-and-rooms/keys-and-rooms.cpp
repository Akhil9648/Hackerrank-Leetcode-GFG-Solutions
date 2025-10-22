class Solution {
public:
    void dfs(int i,vector<vector<int>>&rooms,vector<int>& vis){
        if(i==rooms.size()) return;
        vis[i]=1;
        for(int it:rooms[i]){
            if(vis[it]==0){
                dfs(it,rooms,vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int>vis(n,0);
        dfs(0,rooms,vis);
        for(auto i:vis) if(i==0) return false;
        return true;
    }
};