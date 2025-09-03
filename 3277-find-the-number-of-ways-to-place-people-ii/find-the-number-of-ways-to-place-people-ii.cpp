class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](const vector<int>& a,const vector<int>& b){
            return a[0]<b[0] || (a[0]==b[0] && a[1]>b[1]);
        });
        int n=points.size(),ans=0;
        for(int i=0;i<n;i++){
            int x1=points[i][0],y1=points[i][1];
            int maxY=INT_MIN;
            for(int j=i+1;j<n;j++){
                int x2=points[j][0],y2=points[j][1];
                if(y2>y1) continue;
                if(y2>maxY){
                    ans++;
                    maxY=y2;
                }

            }
        }
        return ans;
    }
};