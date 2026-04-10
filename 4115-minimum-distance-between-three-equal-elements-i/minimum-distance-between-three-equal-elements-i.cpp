class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]==nums[j] && nums[j]==nums[k]) ans=min(ans,(abs(i-j)+abs(j-k)+abs(i-k)));
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};