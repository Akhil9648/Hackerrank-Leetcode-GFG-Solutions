class Solution {
public:
    vector<int> sumZero(int n) {
        if(n==1) return {0};
        if(n==2) return {-1,1};
        int a=0;
        vector<int>ans;
        for(int i=0;i<n-1;i++){
            ans.push_back(i);
            a+=i;
        }
        ans.push_back(a*-1);
        return ans;
    }
};