class Solution {
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