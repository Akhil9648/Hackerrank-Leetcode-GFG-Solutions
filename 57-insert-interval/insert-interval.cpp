class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& ne) {
        vector<vector<int>> ans;
        int n=in.size();
        if(n==0){
            ans.push_back(ne);
            return ans;
        }
        int i=0;
        while(i<n && in[i][1]<ne[0]){
            ans.push_back(in[i]);
            i++;
        }
        while(i<n && in[i][0]<=ne[1]){
            ne[0]=min(ne[0],in[i][0]);
            ne[1]=max(ne[1],in[i][1]);
            i++;
        }
        ans.push_back(ne);
        while(i<n){
            ans.push_back(in[i]);
            i++;
        }
        return ans;
    }
};