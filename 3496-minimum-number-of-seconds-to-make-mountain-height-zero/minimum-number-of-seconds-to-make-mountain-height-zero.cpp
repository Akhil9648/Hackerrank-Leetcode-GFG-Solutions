class Solution {
public:
    bool check(long long mid,int mountainHeight,vector<int>& workerTimes){
        for(int i:workerTimes){
            int k=1;
            long long sum=0;
            while(sum + 1LL * i * k <= mid){
                sum+=1LL*i*k;
                if(k>=mountainHeight) return true;
                k++;
            }
            mountainHeight-=(k-1);
            if(mountainHeight<=0) return true;
        }
        return false;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int n=workerTimes.size();
        long long low=0,high=1LL*(*max_element(workerTimes.begin(),workerTimes.end())) * mountainHeight * (mountainHeight + 1) / 2;
        long long ans=0;
        while(low<=high){
            long long mid=(low+high)/2;
            if(check(mid,mountainHeight,workerTimes)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};