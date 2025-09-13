class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int sum=0;
        for(int i:nums){
            sum+=i;
        }
        if(sum<0) sum=0;
        sum/=nums.size();
        // if(sum<0) sum=0;
        while(++sum<*max_element(nums.begin(),nums.end())+2 && sum>0){
            if(st.find(sum)==st.end()) return sum;
        }
        return 1;
    }
};