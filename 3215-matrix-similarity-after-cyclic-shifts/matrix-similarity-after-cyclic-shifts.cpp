class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        k%=m;
        vector<vector<int>>ans(n,vector<int>(m,0)),temp(n,vector<int>(m,0));
        temp=mat;
        ans=temp;
        while(k--){
            for(int i=0;i<n;i++){
                ans[i][m-1]=temp[i][0];
                for(int j=m-1;j>0;j--){
                    ans[i][j-1]=temp[i][j];
                }
            }
            temp=ans;
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<ans[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return mat==ans;
    }
};