class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> asc(n),dsc(n);
        for(int i=0;i<n;i++){
            asc[i]=abs(nums[i]);
            dsc[i]=abs(nums[i]);
        }
        sort(asc.begin(),asc.end());
        sort(dsc.begin(),dsc.end(),greater<int>());
        int l=0,r=0;
        long long sum=0;
        int i=0;
        while(i<n){
            if(i%2==0){
                sum+=(dsc[r]*dsc[r]);
                r++;
            }
            else{
                sum-=(asc[l]*asc[l]);
                l++;
            }
            i++;
        }
        return sum;
    }
};