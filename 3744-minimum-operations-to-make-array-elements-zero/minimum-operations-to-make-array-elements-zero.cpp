class Solution1 {
public:
    int minop(vector<int>& arr){
        int i=0,j=0;
        while(i<arr.size()){
            while(arr[i]>0){
                arr[i]/=4;
                j++;
            }
            i++;   
        }
        if(j%2==1) j++;
        j/=2;
        return j;
    }
    long long minOperations(vector<vector<int>>& queries) {
        int n=queries.size(),cnt=0;
        for(int i=0;i<n;i++){
            vector<int>arr;
            for(int j=queries[i][0];j<=queries[i][1];j++){
                arr.push_back(j);
            }
            cnt+=minop(arr);
        }
        return cnt;
    }
};
class Solution {
public:
    long long minop(int l,int r){
        long long k=1;
        long long ans=0;
        long long L=1;
        while(L<=r){
            long long R=L*4-1;
            long long i=max(L,(long long)l);
            long long j=min(R,(long long)r);
            if(i<=j){
            ans+=(j-i+1)*k;
            }
            k++;
            L*=4;
        }
        if(ans%2==1) ans++;
        return ans/2;
    }
    long long minOperations(vector<vector<int>>& queries) {
        int n=queries.size();
        long long cnt=0;
        for(int i=0;i<n;i++){
            cnt+=minop(queries[i][0],queries[i][1]);
        }
        return cnt;
    }
};