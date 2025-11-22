class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int m=target.size();
        vector<string>ans;
        int j=1;
        for(int i=0;i<m;i++){
            while(target[i]!=j){
                ans.push_back("Push");
                ans.push_back("Pop");
                j++;
            }
            ans.push_back("Push");
            j++;
        }   
        return ans;
    }
};