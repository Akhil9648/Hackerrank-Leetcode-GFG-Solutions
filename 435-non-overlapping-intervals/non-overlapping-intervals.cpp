class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const auto &a,const auto &b){
            return a[1]<b[1];
        });
        int count=1,a=intervals[0][1];
        for(auto i:intervals){
            if(i[0]>=a){
                count++;
                a=i[1];
            }
        }
        return intervals.size()-count;
    }
};