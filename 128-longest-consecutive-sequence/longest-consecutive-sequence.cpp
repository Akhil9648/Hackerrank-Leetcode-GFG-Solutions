class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxi=0,curr=1;
        int n=nums.size();
        if(n==0) return 0;
        for(int i=1;i<n;i++){
            if(nums[i]==(nums[i-1]+1)){
                curr++;
            }
            else if(nums[i]==nums[i-1]) continue;
            else{
                maxi=max(maxi,curr);
                curr=1;
            }
        }
        maxi=max(maxi,curr);
        return maxi;
    }
};