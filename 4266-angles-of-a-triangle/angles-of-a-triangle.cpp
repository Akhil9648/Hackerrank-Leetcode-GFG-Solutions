class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        sort(sides.begin(),sides.end());
        int a=sides[0],b=sides[1],c=sides[2];
        if(a+b<=c) return {};
        double ana = (double)(b*b + c*c - a*a) / (2.0 * b * c);
        double anb = (double)(a*a + c*c - b*b) / (2.0 * a * c);
        double anc = (double)(a*a + b*b - c*c) / (2.0 * a * b);
        ana = max(-1.0, min(1.0, ana));
        anb = max(-1.0, min(1.0, anb));
        anc = max(-1.0, min(1.0, anc));;
        vector<double>ans;
        ans.push_back(acos(ana)*180/M_PI);
        ans.push_back(acos(anb)*180/M_PI);
        ans.push_back(acos(anc)*180/M_PI);
        sort(ans.begin(),ans.end());
        return ans;
    }
};