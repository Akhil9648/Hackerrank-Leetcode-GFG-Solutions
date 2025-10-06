class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        for(auto it:prerequisites){
            adj[it[0]].push_back(it[1]);
        }
        vector<int>inor(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i]){
                inor[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(inor[i]==0) q.push(i);
        }
        vector<int>topo;
        while(!q.empty()){
            int a=q.front();
            q.pop();
            topo.push_back(a);
            for(auto it:adj[a]){
                inor[it]--;
                if(inor[it]==0) q.push(it);
            }
        }
        if(topo.size()==numCourses) return true;
        return false;
    }
};