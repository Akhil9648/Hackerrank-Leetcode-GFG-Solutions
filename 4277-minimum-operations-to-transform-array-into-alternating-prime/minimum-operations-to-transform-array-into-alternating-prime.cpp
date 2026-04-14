class Solution {
public:
    bool isPrime(int n){
        if(n==1) return false;
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0) return false;
        }
        return true;
    }
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                while(!isPrime(nums[i])){
                    nums[i]++;
                    cnt++;
                }
                cout<<nums[i]<<" ";
            }
            else{
                while(isPrime(nums[i])){
                    nums[i]++;
                    cnt++;
                }
                cout<<nums[i]<<" ";
            }
        }
        return cnt;
    }
};