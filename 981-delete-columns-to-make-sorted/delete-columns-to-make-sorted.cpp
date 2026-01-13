class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();
        int m=strs[0].size();
        vector<int>arr(m,0);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(strs[i][j]<strs[i-1][j]) arr[j]=1;
            }
        }
        int count=0;
        for(int j=0;j<m;j++){
            if(arr[j]) count++;
        }
        return count;
    }
};