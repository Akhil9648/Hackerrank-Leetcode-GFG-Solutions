class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
        });
        int n=people.size();
        int pos=0;
        vector<vector<int>>ans(n,vector<int>(2,-1));
        for(int i=0;i<n;i++){
            int cnt=people[i][1];
            for(int j=0;j<n;j++){
                if (ans[j][0] == -1) {
                    if (cnt == 0) {
                        ans[j] = people[i];
                        break;
                    }
                    cnt--; 
                }
            }
        }
        return ans;
    }
};