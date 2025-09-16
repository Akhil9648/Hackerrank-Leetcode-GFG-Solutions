class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
       sort(points.begin(),points.end(),[](const vector<int> &a,const vector<int> &b){
        return a[1]<b[1];
       });
       int count=0;
       int n=points.size();
       for(int i=0;i<points.size();i++){
            int j=i;
            while(j<n && points[j][0]<=points[i][1]){
                j++;
            }
            if(i!=j){
                count++;
            }
            i=j-1;
       } 
       return count;
    }
};