class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>arr;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr.push_back(grid[i][j]);
            }
        }
        sort(arr.begin(),arr.end());
        n=arr.size();
        int a=arr[n/2];
        int cnt=0;
        for(int i:arr){
            int diff=abs(a-i);
            if(diff%x!=0) return -1;
            cnt+=(diff/x);
        }
        return cnt;
    }
};