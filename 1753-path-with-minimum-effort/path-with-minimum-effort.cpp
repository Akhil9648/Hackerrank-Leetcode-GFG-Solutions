class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        int dr[]={1,0,-1,0};
        int dc[]={0,1,0,-1};
        while(!pq.empty()){
            auto it=pq.top();
            int dis=it.first;
            int r=it.second.first;
            int c=it.second.second;
            pq.pop();
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int newd=max(abs(heights[nr][nc]-heights[r][c]),dis);
                    if(newd<dist[nr][nc]){
                        dist[nr][nc]=newd;
                        pq.push({dist[nr][nc],{nr,nc}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};