class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](const auto &a,const auto &b){
            if(a[1]==b[1]) return a[0]<b[0];
            return a[1]<b[1];
        });
        int prev=points[0][1];
        int ans=1;
        int n=points.size();
        for(int i=1;i<n;i++){
            if(points[i][0]>prev){
                prev=points[i][1];
                ans++;
            }
        }
        return ans;
    }
};