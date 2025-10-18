class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int>l(n,0),r(n,0);
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            l[i]=sum;
        }
        sum=0;
        for(int i=n-1;i>=0;i--){
            sum+=nums[i];
            r[i]=sum;
        }
        for(int i=0;i<n;i++){
            if(l[i]==r[i]) return i;
        }
        return -1;
    }
};