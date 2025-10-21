class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int>mp;
        int n=grid.size();
        for(int i=0;i<n;i++){
            vector<int>ans;
            for(int j=0;j<n;j++){
                ans.push_back(grid[i][j]);
            }
            mp[ans]++;
        }
        int count=0;
        for(int i=0;i<n;i++){
            vector<int>ans;
            for(int j=0;j<n;j++){
                ans.push_back(grid[j][i]);
            }
            count+=mp[ans];
        }
        return count;
    }
};