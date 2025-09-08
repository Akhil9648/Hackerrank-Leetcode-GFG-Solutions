class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>maxp;
        for(int i:nums){
            maxp.push(i);
        }
        while(--k){
            maxp.pop();
        }
        return maxp.top();
    }
};