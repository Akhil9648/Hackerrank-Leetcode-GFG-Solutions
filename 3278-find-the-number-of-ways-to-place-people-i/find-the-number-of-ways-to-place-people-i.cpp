// BruteForce O(n^3)
class Solution1 {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n=points.size(),count=0;
        for(int i=0;i<n;i++){
            int x1=points[i][0],y1=points[i][1];
            for(int j=0;j<n;j++){
                if(i==j) continue;
                int x2=points[j][0],y2=points[j][1];
                if(x1<=x2 && y1>=y2){
                   bool valid=true;
                for(int k=0;k<n;k++){
                    if(k==i || k==j) continue;
                    int x=points[k][0],y=points[k][1];
                    if(x1<=x && x<=x2 && y1>=y && y>=y2){
                        valid=false;
                        break;
                    }
                }
                if(valid) count++;
                }
            }
        }
     return count;
    }
};
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n=points.size(),count=0;
        auto lambda=[](vector<int>&point1,vector<int>&point2){
            if(point1[0]==point2[0]) return point1[1]>point2[1];
            return point1[0]<point2[0];
        };
        sort(points.begin(),points.end(),lambda);
        for(int i=0;i<n;i++){
            int x1=points[i][0],y1=points[i][1];
            int maxY=INT_MIN;
            for(int j=i+1;j<n;j++){
                int x2=points[j][0],y2=points[j][1];
                if(y2>y1) continue;
                if(y2>maxY){
                    count++;
                    maxY=y2;
                }
            }
        }
        return count;
    }
    };