class Solution1 {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n=obstacles.size();
        vector<int>ans(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(obstacles[j]<=obstacles[i]){
                    ans[i]=max(ans[i],ans[j]+1);
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n=obstacles.size();
        vector<int>ans(n),LIS;
        for(int i=0;i<n;i++){
            int idx=upper_bound(LIS.begin(),LIS.end(),obstacles[i])-LIS.begin();
            if(idx==LIS.size()) LIS.push_back(obstacles[i]);
            else LIS[idx]=obstacles[i];
            ans[i]=idx+1;
        }
        return ans;
    }
};