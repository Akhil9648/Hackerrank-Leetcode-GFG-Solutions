class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        k%=m;
        vector<vector<int>>ans(n,vector<int>(m,0));
        // temp=mat;
        ans=mat;
        while(k--){
            for(int i=0;i<n;i++){
                int a=ans[i][m-1];
                int b=0;
                ans[i][m-1]=ans[i][0];
                for(int j=m-1;j>0;j--){
                    b=ans[i][j-1];
                    ans[i][j-1]=a;
                    a=b;
                }
            }
        }
        return mat==ans;
    }
};