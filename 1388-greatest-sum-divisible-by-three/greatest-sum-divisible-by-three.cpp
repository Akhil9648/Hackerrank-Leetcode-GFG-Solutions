class Solution1 {
public:
    int n;
    int solve(int i,vector<int>& nums,int sum){
        if(i>=n) return 0;
        if(sum<0) return 0;
        if(sum%3==0) return sum;
        int take=solve(i+1,nums,sum-nums[i]);
        int notTake=solve(i+1,nums,sum);
        return max(take,notTake);
    }
    int maxSumDivThree(vector<int>& nums) {
        int sum=0;
        n=nums.size();
        for(int i:nums) sum+=i;
        sort(nums.begin(),nums.end());
        if(sum%3==0) return sum;
        return solve(0,nums,sum);
    }
};
class Solution {
public:
    int n;
    int maxSumDivThree(vector<int>& nums) {
        int sum=0;
        n=nums.size();
        vector<int>one,two;
        for(int i:nums){
            sum+=i;
            if(i%3==1) one.push_back(i);
            else if(i%3==2) two.push_back(i);
        }
        sort(one.begin(),one.end());
        sort(two.begin(),two.end());
        if(sum%3==0) return sum;
        int rem1=INT_MAX,rem2=INT_MAX;
        if(sum%3==1){
            if(one.size()>0) rem1=one[0];
            if(two.size()>=2) rem2=two[0]+two[1];
            return sum-min(rem1,rem2);
        }
        if(sum%3==2){
            if(two.size()>0) rem1=two[0];
            if(one.size()>=2) rem2=one[0]+one[1];
            return sum-min(rem1,rem2);
        }
        return 0;
    }
};