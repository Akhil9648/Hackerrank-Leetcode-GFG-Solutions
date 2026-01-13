class Solution {
public:
    double check(vector<vector<int>>& squares,double mid){
        double area=0;
        for(const auto &s:squares){
            double bottom=s[1];
            double top=s[1]+s[2];
            double side=s[2];
            if(mid<=bottom){
                continue;
            }
            else if(mid>=top){
                area+=side*side;
            }
            else{
                area+=(mid-bottom)*side;
            }
        }
        return area;
    }
    double separateSquares(vector<vector<int>>& squares) {
        int n=squares.size();
        double low=1e18;
        double high=0;
        double totalarea=0;
        for(int i=0;i<n;i++){
            double y = squares[i][1];
            double side = squares[i][2];
            low=min(low,y);
            high=max(high,y+side);
            totalarea+=side*side;
        }
        totalarea/=2.0;
        double ans=0;
        for(int it = 0; it < 60; it++){
            double mid=(low+high)/2.0;
            if(check(squares,mid)>=totalarea){
                high=mid;
                ans=mid;
            }
            else{
                low=mid;
            }
        }
        return ans;
    }
};