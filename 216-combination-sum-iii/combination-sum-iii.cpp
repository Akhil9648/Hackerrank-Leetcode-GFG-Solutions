class Solution {
public:
    void solve(int i,vector<vector<int>>& ans,vector<int>& curr,int sum,int n,int prev,int k){
        if(i==k){
            if(sum==n){
                ans.push_back(curr);
                return;
            }
            return;
        }
        if(i>k) return;
        for(int j=prev+1;j<=min(n,9);j++){
            if(sum+j>n) continue;
            curr.push_back(j);
            solve(i+1,ans,curr,sum+j,n,j,k);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>curr;

        solve(0,ans,curr,0,n,0,k);
        return ans;
    }
};