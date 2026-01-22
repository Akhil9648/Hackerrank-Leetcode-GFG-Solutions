class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr=nums;
        sort(arr.begin(),arr.end());
        int count=0;
        while(arr!=nums){
        int mini=INT_MAX,ind=-1;
        for(int i=0;i<nums.size()-1;i++){
            int a=nums[i]+nums[i+1];
            if(mini>a){
                mini=a;
                ind=i;
            }
        }
        nums[ind]=mini;
        nums.erase(nums.begin()+ind+1);
        for(int i=0;i<nums.size();i++){
            cout<<nums[i]<<" ";
        }
        cout<<"\n";
        arr=nums;
        sort(arr.begin(),arr.end());
        count++;
        }
        return count;
    }
};