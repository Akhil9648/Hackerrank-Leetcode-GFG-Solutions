class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1) return 1;
        vector<pair<int,int>>node(n+1);
        for(auto it:trust){
            node[it[0]].second++;
            node[it[1]].first++;
        }
        int flag=-1;
        int j=0;
        for(auto it:node){
            if(it.first==n-1 && it.second==0){
                if(flag==-1) flag=j;
                else return -1;
            }
            j++;
        }
        return flag;
    }
};