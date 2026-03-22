class Solution {
public:
    int n;
    vector<vector<int>> rotate(vector<vector<int>>& mat){
        vector<vector<int>>ans(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=mat[n-j-1][i];
            }
        }
        return ans;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        n=mat.size();
        int a=n+1;
        if(mat==target) return true;
        while(a){
            mat=rotate(mat);
            if(mat==target) return true;
            a--;
        }
        return false;
    }
};