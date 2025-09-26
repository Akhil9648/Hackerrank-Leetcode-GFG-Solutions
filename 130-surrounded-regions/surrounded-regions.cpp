class Solution {
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