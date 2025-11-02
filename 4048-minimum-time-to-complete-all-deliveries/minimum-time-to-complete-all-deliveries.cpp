class Solution {
public:
    int check(vector<int>& d,vector<int>& r,long long t){
        long long a=t-t/r[0];
        long long b=t-t/r[1];
        long long both = t - t / lcm((long long)r[0], (long long)r[1]);
        return (a>=d[0] && b>=d[1] && (d[0]+d[1])<=both);
    }
    long long minimumTime(vector<int>& d, vector<int>& r) {
        long long high=1e12;
        long long low=1,ans=0;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(check(d,r,mid)){
                high=mid-1;
                ans=mid;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};