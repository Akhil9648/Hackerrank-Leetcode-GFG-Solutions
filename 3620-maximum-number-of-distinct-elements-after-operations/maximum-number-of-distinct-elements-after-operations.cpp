class Solution1 {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        set<int>st;
        sort(nums.begin(), nums.end());
        for(int it:nums){
            for(int i=-k;i<=k;i++){
                if(st.find(it+i)!=st.end()) continue;
                st.insert(it+i);
                break;
            }
        }
        return st.size();
    }
};
class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        set<int>st;
        sort(nums.begin(), nums.end());
        for(int it:nums){
            int low=-k,high=k;
            int a=0;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(st.find(it+mid)!=st.end()){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                    a=mid;
                }
            }
            st.insert(it+a);
        }
        return st.size();
    }
};