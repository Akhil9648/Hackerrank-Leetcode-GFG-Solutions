class Solution {
public:
    void solve(int n,int i,int k,vector<int>& ans,int curr){
        if(i==n){
            ans.push_back(curr);
            return;
        }
        if(i==0){
            for(int j=1;j<=9;j++){
                solve(n,i+1,k,ans,j);
            }
        }
        else{
                if(curr%10+k<=9){
                    int a=(curr*10+k+curr%10);
                    solve(n,i+1,k,ans,a);
                    if(k==0) return;
                }
                if(curr%10-k>=0){
                    curr=curr*10+(curr%10-k);
                    solve(n,i+1,k,ans,curr);
                }
            }  
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>ans;
        solve(n,0,k,ans,0);
        return ans;
    }
};