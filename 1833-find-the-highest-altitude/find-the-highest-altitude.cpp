class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        vector<int>arr(n+1,0);
        for(int i=1;i<=n;i++){
            arr[i]=gain[i-1]+arr[i-1];
            cout<<arr[i]<<" ";
        }
        int a=*max_element(arr.begin(),arr.end());
        return a;
    }
};