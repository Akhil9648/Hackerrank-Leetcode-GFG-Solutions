class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>mat(n,vector<int>(n,0));
        for(auto it:queries){
            int a=it[0],b=it[1],c=it[2],d=it[3];
            for(int i=a;i<=c;i++){
                for(int j=b;j<=d;j++){
                    mat[i][j]++;
                }
            }
        }
        return mat;
    }
};