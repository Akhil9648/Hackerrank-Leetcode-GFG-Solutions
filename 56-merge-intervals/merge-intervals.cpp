class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const auto &a,const auto &b){
            if(a[0]==b[0]){
                return a[1]<b[1];
            }
            return a[0]<b[0];
        });
        int n=intervals.size();
        int b=intervals[0][0];
        int a=intervals[0][1];
        vector<vector<int>>ans;
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=a){
                a=max(a,intervals[i][1]);
            }
            else{
                ans.push_back({b,a});
                b=intervals[i][0];
                a=intervals[i][1];
            }
        }
        ans.push_back({b,a});
        return ans;
    }
};