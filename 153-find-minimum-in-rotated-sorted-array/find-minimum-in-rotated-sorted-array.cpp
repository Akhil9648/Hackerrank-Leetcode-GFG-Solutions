class Solution {
public:
    int findMin(vector<int>& arr) {
        int n=arr.size();
        int low=0,high=n-1;
        int mini=INT_MAX;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[low]>arr[high] && arr[mid]>arr[high]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
            mini=min(mini,arr[mid]);
        }
        return mini;
    }
};