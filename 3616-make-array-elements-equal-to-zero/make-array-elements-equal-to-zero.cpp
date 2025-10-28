class Solution {
public:
    bool check(vector<int>&arr){
        for(int i:arr){
            if(i>0) return false;
        }
        return true;
    }
    bool perform(vector<int>arr,int i,int flag){
        int n=arr.size();
        while(i>=0 && i<n){
            while(i >= 0 && i < n && arr[i]==0){
                if(flag) i++;
                else i--;
            }
            if (i < 0 || i >= n) break;
            arr[i]--;
            flag==1?i--:i++;
            flag=!flag;
        }
        return check(arr);
    }
    int countValidSelections(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0 && perform(nums,i,0)){
                count++;
            }
            if(nums[i]==0 && perform(nums,i,1)){
                count++;
            }
        }
        return count;
    }
};