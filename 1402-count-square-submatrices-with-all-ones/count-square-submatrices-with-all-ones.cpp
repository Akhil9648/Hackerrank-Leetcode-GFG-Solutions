class Solution {
public:
    int n,m;
    bool get(int i,int j,vector<vector<int>>& arr){
        int s=arr[i][j];
        for(int c=j;c<=j+s;c++){
            if(i+s>=n || c>=m || arr[i+s][c]==0) return false;
        }
        for(int c=i;c<=i+s;c++){
            if(j+s>=m || c>=n || arr[c][j+s]==0) return false;
        }
        return true;
    }
    int countSquares(vector<vector<int>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        int cnt=min(n,m);
        while(cnt--){
        vector<pair<int,int>>upd;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]>0){
                    if(get(i,j,matrix)) upd.push_back({i,j});
                }
            }
        }
            for(auto &p: upd)
                matrix[p.first][p.second]++;
        }
        int sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<matrix[i][j]<<" ";
                sum+=matrix[i][j];
            }
            cout<<endl;
        }
        return sum;
    }
};