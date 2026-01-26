class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int mini=INT_MAX;
        for(int i=0;i<n-1;i++){
            mini=min(mini,arr[i+1]-arr[i]);
        }
        vector<vector<int>>ans;
        for(int i=0;i<n-1;i++){
            if((arr[i+1]-arr[i])==mini){
                ans.push_back({arr[i],arr[i+1]});
            }
        }
        return ans;
    }
};