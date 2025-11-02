class Solution1 {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>arr(m,vector<int>(n,1));
        for(auto it:guards){
            arr[it[0]][it[1]]=2;
        }
        for(auto it:walls){
            arr[it[0]][it[1]]=3;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]==2){
                    int u=i,v=j;
                    while(u<m && arr[u][j]!=3){
                        if(arr[u][j]==2){
                            u++;
                            continue;
                        }
                        arr[u][j]=0;
                        u++;
                    }
                    u=i;
                    while(u>=0 && arr[u][j]!=3){
                        if(arr[u][j]==2){
                            u--;
                            continue;
                        }
                        arr[u][j]=0;
                        u--;
                    }
                    while(v<n && arr[i][v]!=3){
                        if(arr[i][v]==2){
                            v++;
                            continue;
                        }
                        arr[i][v]=0;
                        v++;
                    }
                    v=j;
                    while(v>=0 && arr[i][v]!=3){
                        if(arr[i][v]==2){
                            v--;
                            continue;
                        }
                        arr[i][v]=0;
                        v--;
                    }
                }
            }
        }
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]==1) count++;
            }
        }
        return count;
    }
};
class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>arr(m,vector<int>(n,1));
        for(auto it:guards){
            arr[it[0]][it[1]]=2;
        }
        for(auto it:walls){
            arr[it[0]][it[1]]=3;
        }
        int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
        for(auto &g:guards){
            int x=g[0],y=g[1];
            for(auto &d:dir){
                int i=x+d[0];
                int j=y+d[1];
                while(i>=0 && i<m && j>=0 && j<n && arr[i][j]!=2 && arr[i][j]!=3){
                    arr[i][j]=0;
                    i+=d[0];
                    j+=d[1];
                }
            }
        }
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]==1) count++;
            }
        }
        return count;
    }
};