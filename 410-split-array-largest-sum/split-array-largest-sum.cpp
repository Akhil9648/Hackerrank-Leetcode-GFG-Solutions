class Solution1 {
public:
    int n;
    int solve(int i,vector<int>& nums,int k,int sum,vector<int>& arr){
        if(i>=n){
            arr.push_back(sum);
            int a=*max_element(arr.begin(),arr.end());
            arr.pop_back();
            return a;
        }
        int take=INT_MAX;
        if(k>1){
            arr.push_back(sum);
            take=solve(i+1,nums,k-1,nums[i],arr);
            arr.pop_back();
        }
        int notTake=solve(i+1,nums,k,sum+nums[i],arr);
        return min(take,notTake);
    }
    int splitArray(vector<int>& nums, int k) {
        vector<int>arr;
        n=nums.size();
        return solve(1,nums,k,nums[0],arr);
    }
};
class Solution {
public:
    bool canSolve(vector<int>& nums,int k,int mid){
        int sum=0,cnt=1;
        for(int i:nums){
            if(sum+i<=mid){
                sum+=i;
            }
            else{
                sum=i;
                cnt++;
            }
            if(cnt>k) return false;
        }
        return cnt<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int low=*max_element(nums.begin(),nums.end());
        int high=0;
        int ans=0;
        for(int i:nums){
            high+=i;
        }
        while(low<=high){
            int mid=(low+high)/2;
            if(canSolve(nums,k,mid)){
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