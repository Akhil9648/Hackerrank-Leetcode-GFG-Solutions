// Approach-1 TLE
class Solution1 {
public:
    int longestSubsequence(vector<int>& nums) {
        int l=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int XOR=nums[i];
            if(XOR>0) l=max(l,1);
            for(int j=i+1;j<n;j++){
                XOR^=nums[j];
                if(XOR>0){
                    l=max(l,j-i+1);
                }
            }
        }
        return l;
    }
};
// Approach-2
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int a=0,flag=0;
        for(int i:nums){
            a^=i;
            if(a>0) flag=1;
        }
        if(a==0 && flag==1) return nums.size()-1;
        if(a==0 && flag==0) return 0;
        return nums.size();
    }
};