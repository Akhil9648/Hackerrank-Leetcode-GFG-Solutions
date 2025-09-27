class Solution1{
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double area=0;
        int n=points.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    double a=hypot(points[i][0]-points[j][0],points[i][1]-points[j][1]);
                    double b=hypot(points[i][0]-points[k][0],points[i][1]-points[k][1]);
                    double c=hypot(points[k][0]-points[j][0],points[k][1]-points[j][1]);
                    double s=(a+b+c)*0.5;
                    double inside=s*(s-a)*(s-b)*(s-c);
                    if(inside<0) inside=0; 
                    double ar=sqrt(inside);
                    area=max(ar,area);
                }
            }
        }
        return area;
    }
};
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double area=0;
        int n=points.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    double x1=points[i][0],x2=points[j][0],x3=points[k][0];
                    double y1=points[i][1],y2=points[j][1],y3=points[k][1];
                    double ar=0.5*fabs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
                    area=max(ar,area);
                }
            }
        }
        return area;
    }
};