class Solution1 {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr(n);
        arr[0]=nums[0];
        for(int i=1;i<n;i++){
            arr[i]=arr[i-1]+nums[i];
        }
        for(int i=1;i<n-1;i++){
            // if()
        }
        return 0;
    }
};
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int sum1=0;
        for(int i=0;i<n-1;i++){
            sum1+=nums[i];
            int sum2=0;
            for(int j=i+1;j<n;j++){
                sum2+=nums[j];
            }
            if(abs(sum1-sum2)%2==0) count++;
        }
        return count;
    }
};