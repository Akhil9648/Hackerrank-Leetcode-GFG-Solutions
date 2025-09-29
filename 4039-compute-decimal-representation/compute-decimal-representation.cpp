class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        int a=0;
        vector<int>ans;
        int num=n;
        while(num){
            int d=num%10;
            int c=d*pow(10,a);
            a++;
            num/=10;
            if(c>0) ans.push_back(c);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};