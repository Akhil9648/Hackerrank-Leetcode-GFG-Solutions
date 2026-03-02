class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        int ans=0;
        vector<int>arr;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]!=0) break;
                cnt++;
            }
            arr.push_back(cnt);
        }
        for(int i=0;i<n;i++){
            int need=n-i-1;
            int j=i;
            while(j<n && arr[j]<need){
                j++;
            }
            if(j==n) return -1;
            else ans+=(j-i);
            while(j>i){
                swap(arr[j],arr[j-1]);
                j--;
            }
        }
        return ans;
    }
};