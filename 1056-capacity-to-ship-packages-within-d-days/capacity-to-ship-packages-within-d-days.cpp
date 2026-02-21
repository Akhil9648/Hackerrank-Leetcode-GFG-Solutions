class Solution {
public:
    bool canLoad(int mid,vector<int>& weights,int days,int n){
        int day=1;
        int load=0;
        for(int i=0;i<n;i++){
            if (weights[i] > mid) return false;
            if(load+weights[i]<=mid) load+=weights[i];
            else{
                load=weights[i];
                day++;
            }
            if(day>days) return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int sum=0,ans=0;
        for(int i:weights) sum+=i;
        int low=0,high=sum;
        while(low<=high){
            int mid=(low+high)/2;
            if(canLoad(mid,weights,days,n)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};