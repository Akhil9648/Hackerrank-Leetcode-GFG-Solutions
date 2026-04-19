class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int ans=0;
        reverse(nums2.begin(),nums2.end());
        for(int i=0;i<n;i++){
            int j=lower_bound(nums2.begin(),nums2.end(),nums1[i])-nums2.begin();
            j=(m-j-1);
            ans=max(ans,j-i);
        }
        return ans;
    }
};