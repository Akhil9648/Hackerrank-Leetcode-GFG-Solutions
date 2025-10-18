class Solution1 {
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
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        for(int i=1;i<n;i++){
            gain[i]+=gain[i-1];
        }
        sort(gain.begin(),gain.end());
        return gain[n-1]<0?0:gain[n-1];
    }
};