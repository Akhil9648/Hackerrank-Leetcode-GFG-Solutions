class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<vector<int>,int>>sorted;
        for(auto it=0;it<intervals.size();it++){
            sorted.push_back({intervals[it],it});
        }
        sort(sorted.begin(),sorted.end());
        int n=intervals.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            int low=0,high=n-1;
            int ind=-1;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(sorted[mid].first[0]>=intervals[i][1]){
                    ind=sorted[mid].second;
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            ans[i]=ind;
        }
        return ans;
    }
};