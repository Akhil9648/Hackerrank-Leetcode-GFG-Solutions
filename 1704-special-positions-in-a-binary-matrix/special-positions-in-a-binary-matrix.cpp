class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1){
                    int flag=0;
                    for(int u=0;u<n;u++){
                        if(mat[u][j]==1 && u!=i){
                            flag=1;
                            break;
                        }
                    }
                    for(int u=0;u<m;u++){
                        if(mat[i][u]==1 && u!=j){
                            flag=1;
                            break;
                        }
                    }
                    if(flag==0) cnt++;
                }
            }
        }
        return cnt;
    }
};