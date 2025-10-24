class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{entrance[0],entrance[1]}});
        int m=maze.size(),n=maze[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        vis[entrance[0]][entrance[1]]=1;
        int ans=INT_MAX;
        int dirs[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        while(!q.empty()){
            auto u=q.front();
            q.pop();
            int dist=u.first;
            int a=u.second.first;
            int b=u.second.second;
            if(maze[a][b]=='.' && (a==0 || b==0 || a==m-1 || b==n-1) && !(a==entrance[0] && b==entrance[1])){
                ans=min(ans,dist);
            }
            for(int k=0; k<4; k++){
                int na = a + dirs[k][0];
                int nb = b + dirs[k][1];
                if(na>=0 && na<m && nb>=0 && nb<n && !vis[na][nb] && maze[na][nb]=='.'){
                    q.push({dist+1, {na, nb}});
                    vis[na][nb] = 1;
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};