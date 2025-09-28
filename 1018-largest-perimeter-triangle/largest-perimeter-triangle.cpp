class Solution1 {
public:
    int largestPerimeter(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    int a=nums[i];
                    int b=nums[j];
                    int c=nums[k];
                    if((a+b>c) && (b+c>a) && (a+c>b)){
                        ans=max(ans,a+b+c);
                    }
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        sort(nums.begin(),nums.end(),greater<int>());
        int i=0;
        while(i<n-2){
            int a=nums[i],b=nums[i+1],c=nums[i+2];
            if((a+b>c) && (b+c>a) && (a+c>b)){
                ans=a+b+c;
                break;
            }
            i++;
        }
        return ans;
    }
};