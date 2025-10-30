class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int mx=*max_element(nums.begin(),nums.end());
        vector<int>points(mx+1,0);
        for(int x:nums){
            points[x]+=x;
        }
        int prev1=points[0],prev2=0;
        for(int i=1;i<mx+1;i++){
            int cur=max(prev1,prev2+points[i]);
            prev2=prev1;
            prev1=cur;
        }
        return prev1;
    }
};