class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq(stones.begin(),stones.end());
        while(pq.size()>1){
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            if(a==b){
                if(pq.size()==0) return 0;
                continue;
            }
            else pq.push(a-b);
        }
        return pq.top();
    }
};