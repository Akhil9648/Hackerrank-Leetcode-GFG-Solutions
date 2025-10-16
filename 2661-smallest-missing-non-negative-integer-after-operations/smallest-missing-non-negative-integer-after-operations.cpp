class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int>a(value,0);
        for(int &i:nums){
            i=((i%value)+value)%value;
            a[i]++;
        }
        int mini=*min_element(a.begin(),a.end());
        for(int i=0;i<value;i++){
            if(a[i]==mini){
                return i+mini*value;
            }
        }
        return 0;
    }
};