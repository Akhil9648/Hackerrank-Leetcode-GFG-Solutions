class Solution {
public:
    vector<int>dr={1,0,-1,0};
    vector<int>dc={0,1,0,-1};
    int n,m,u;
    bool dfs(int i,int j,int k,vector<vector<char>>& grid,string &word,vector<vector<int>>& vis){
        vis[i][j]=1;
        if(k==u) return true;
        for(int t=0;t<4;t++){
            int nr=i+dr[t];
            int nc=j+dc[t];
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==word[k] && !vis[nr][nc]){
                if(dfs(nr,nc,k+1,grid,word,vis)) return true;
            }
        }
        vis[i][j]=0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();
        u=word.size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(word[0]==board[i][j]){
                    if(dfs(i,j,1,board,word,vis))  return true;
                }
            }
        }
        return false;
    }
};