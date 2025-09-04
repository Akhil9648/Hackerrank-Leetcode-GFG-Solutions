class Solution1 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int maxi=0;
        int n=nums.size();
        vector<int>ans;
        int j=0;
        for(int i=0;i<n-k+1;i++){
            maxi=*max_element(nums.begin()+i,nums.begin()+i+k);
            ans.push_back(maxi);
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        deque<int>q;
        int n=nums.size();
        for(int i=0;i<n;i++){
            while(!q.empty() && q.front()==i-k) q.pop_front();
            while(!q.empty() && nums[q.back()]<nums[i]) q.pop_back();
            q.push_back(i);
            if(i>=k-1) ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};