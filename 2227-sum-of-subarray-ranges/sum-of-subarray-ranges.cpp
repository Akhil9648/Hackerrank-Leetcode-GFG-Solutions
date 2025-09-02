class Solution {

public:
    vector<int> findNSE(vector<int>& nums) {
        int n = nums.size();
        vector<int> nse(n);
        stack<int> st;
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> findPSEE(vector<int>& nums) {
        int n = nums.size();
        vector<int> psee(n);
        stack<int> st;
        for(int i=0; i<n; i++) {
            while(!st.empty() && nums[st.top()] > nums[i])
                st.pop();
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return psee;
    }
    long long sumSubarrayMins(vector<int>& nums) {
        vector<int> nse = findNSE(nums);
        vector<int> psee = findPSEE(nums);
        long long total = 0;
        for(int i=0; i<nums.size(); i++) {
            int left = i - psee[i];
            int right = nse[i] - i;
            total += right * left * 1LL * nums[i];
        }
        return total;
    }
    vector<int> findNGEE(vector<int>& nums) {
        int n = nums.size();
        vector<int> ngee(n);
        stack<int> st;
        for (int i = n-1; i>=0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i])
                st.pop();
            ngee[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ngee;
    }
    vector<int> findPGE(vector<int>& nums) {
        int n = nums.size();
        vector<int> pge(n);
        stack<int> st;
        for (int i=0; i<n; i++) {
            while (!st.empty() && nums[st.top()] <= nums[i])
                st.pop();
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pge;
    }
    long long sumSubarrayMax(vector<int>& nums) {
        vector<int> ngee = findNGEE(nums);
        vector<int> pge = findPGE(nums);
        long long total = 0;
        for (int i=0; i<nums.size(); i++) {
            int left = i - pge[i];
            int right = ngee[i] - i;
            total += right * left * 1LL * nums[i];
        }
        return total;
    }
    long long subArrayRanges(vector<int>& nums) {
        long long maxSum = sumSubarrayMax(nums);
        long long minSum = sumSubarrayMins(nums);
        return maxSum - minSum;
    }

};