class Solution {
public:
int n;
    bool cancover(vector<int>&houses,vector<int>& heaters,int mid){
        int i=0;
        for(auto it:heaters){
            int start=max(0,it-mid);
            int end=min(houses[n-1],it+mid);
            while(i<n && (houses[i]>=start && houses[i]<=end)){
                i++;
            }
            if(i>=n) return true;
        }
        return false;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        n=houses.size();
        int m=heaters.size();
        sort(heaters.begin(),heaters.end());
        sort(houses.begin(),houses.end());
        int a=max(abs(heaters[m-1]-houses[0]),abs(houses[n-1]-heaters[0]));
        int low=0,high=max(a,houses[n-1]);
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(cancover(houses,heaters,mid)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};