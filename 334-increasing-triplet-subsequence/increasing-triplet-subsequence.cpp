class Solution1 {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    if(nums[i]<nums[j] && nums[j]<nums[k]) return true;
                }
            }
        }
        return false;
    }
};
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        int n1=INT_MAX,n2=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]<=n1){
                n1=nums[i];
            }
            else if(nums[i]<=n2){
                n2=nums[i];
            }
            else{
                return true;
            }
        }
        return false;
    }  
};