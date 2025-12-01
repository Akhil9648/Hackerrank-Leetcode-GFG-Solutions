class Solution {
public:
    bool possible(int time,int n,vector<int> batteries){
        long long total=0;
        for(int b:batteries){
            total+=(long long)min(time,b);
            if(total>=1LL*time*n) return true;
        }
        return (total>=1LL*time*n);
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum=0;
        for(int b:batteries) sum+=b;
        long long low=1,high=sum/n;
        long long ans=0;
        while(low<=high){
            long long mid=(low+high)/2;
            if(possible(mid,n,batteries)){
                low=mid+1;
                ans=mid;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};