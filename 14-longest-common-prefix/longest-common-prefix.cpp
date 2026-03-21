class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans=strs[0];
        int n=strs.size();
        for(int i=1;i<n;i++){
            int mini=min(ans.size(),strs[i].size());
            for(int j=0;j<mini;j++){
                if(strs[i][j]!=ans[j]){
                    ans.erase(ans.begin()+j,ans.end());
                    break;
                }
            }
            if(ans.size()>mini){
                ans.erase(ans.begin()+mini,ans.end());
            }
        }
        return ans;
    }
};