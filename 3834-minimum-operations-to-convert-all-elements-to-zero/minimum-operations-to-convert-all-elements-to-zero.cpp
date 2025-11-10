class Solution1 {
public:
    int n;
    int minOperations(vector<int>& nums) {
        n=nums.size();
        int count=0;
        set<int>st(nums.begin(),nums.end());
        if(st.find(0)!=st.end()) st.erase(0);
        if(st.empty()) return 0;
        int mini=*st.begin();
        st.erase(mini);
        int i=0,j=-1;
        while(1){
            int flag=0;
            i=0;
            while(i<n){
                if(nums[i]==mini) flag=1;
                if(nums[i]<mini && flag){
                    count++;
                    flag=0;
                }
                i++;
            }
            if(flag){
                count++;
                flag=0;
            }
            if(st.empty()) break;
            mini=*st.begin();
            st.erase(mini);
        }
        return count;
    }
};
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        stack<int>st;
        int i=0;
        for(int i=0;i<n;i++){
            while(!st.empty() &&  nums[i]<st.top()){
                st.pop();
            }
            if(nums[i]==0) continue;
            if(st.empty() || nums[i]>st.top()){
                st.push(nums[i]);
                count++;
            }
        }
        return count;
    }
};