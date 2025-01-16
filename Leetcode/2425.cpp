class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
    int XOR=0;
        int n=nums1.size();
        int m=nums2.size();
        if(m%2!=0)
        {
            for(int &num:nums1)
            {
                XOR^=num;
            }
        }
        if(n%2!=0)
        {
            for(int &num:nums2)
            {
                XOR^=num;
            }
        }
        return XOR;
    }
};
