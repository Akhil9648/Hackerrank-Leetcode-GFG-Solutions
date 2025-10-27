class Solution {
public:
    int r[4]={0,1,-1,0};
    int c[4]={1,0,0,-1};
    int m,n;
    bool solve(int i,int j,vector<vector<char>>& board,string word,int index){
        if(i<0 || j<0 || i>=m || j>=n || board[i][j] != word[index]) return false;  
        if(index==word.size()-1) return true;
        for(int u=0;u<4;u++){
            int ni=i+r[u];
            int nj=j+c[u];
            char temp=board[i][j];
            board[i][j]='#';
            if(ni>=0 && ni<m && nj>=0 && nj<n){
            if(solve(ni,nj,board,word,index+1)) return true;
            }
            board[i][j]=temp;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m=board.size();
        n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(solve(i,j,board,word,0)) return true;
            }
        }
        return false;
    }
};