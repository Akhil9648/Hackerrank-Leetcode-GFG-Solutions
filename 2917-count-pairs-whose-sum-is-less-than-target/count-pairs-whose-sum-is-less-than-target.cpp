class Solution1 {
public:
    int countPairs(vector<int>& nums, int target) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]<target) cnt++;
            }
        }
        return cnt;
    }
};
class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=n-1;j>i;j--){
                if(nums[i]+nums[j]<target){
                    cnt+=(j-i);
                    break;
                }
            }
        }
        return cnt;
    }
};