class Solution1 {
public:
    void solve(vector<vector<char>>& board) {
       int n=board.size();
       int m=board[0].size();
       queue<pair<int,int>>q;
       vector<vector<int>>vis(n,vector<int>(m,0));
       vector<vector<char>>ans(n,vector<char>(m,'X'));
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='O' && (i==n-1 || j==m-1 || i==0 || j==0)){
                q.push({i,j});
                ans[i][j]='O';
                vis[i][j]=1;
            }
        }
       }
       int dr[]={1,0,-1,0};
       int dc[]={0,1,0,-1};
       while(!q.empty()){
            int a=q.front().first;
            int b=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=a+dr[i];
                int nc=dc[i]+b;
                if(nr>=0 && nr<n && nc>=0 && nc<m && board[nr][nc]=='O' && !vis[nr][nc]){
                    ans[nr][nc]='O';
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                }
            }
       }
       board=ans;
    }
};
class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& vis,vector<vector<char>>&board,int dr[],int dc[]) {
        vis[i][j]=1;
        int n=board.size();
        int m=board[0].size();
        for(int u=0;u<4;u++){
            int nr=i+dr[u];
            int nc=j+dc[u];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && board[nr][nc]=='O'){
                dfs(nr,nc,vis,board,dr,dc);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int nr[]={1,0,-1,0};
        int nc[]={0,1,0,-1};
        for(int i=0;i<n;i++){
            if(board[i][0]=='O' && !vis[i][0]){
                dfs(i,0,vis,board,nr,nc);
            }
            if(board[i][m-1]=='O' && !vis[i][m-1]){
                dfs(i,m-1,vis,board,nr,nc);
            }
        }
        for(int j=0;j<m;j++){
            if(board[0][j]=='O' && !vis[0][j]){
                dfs(0,j,vis,board,nr,nc);
            }
            if(board[n-1][j]=='O' && !vis[n-1][j]){
                dfs(n-1,j,vis,board,nr,nc);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};