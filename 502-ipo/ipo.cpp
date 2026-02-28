class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int n=profits.size();
        for(int i=0;i<n;i++){
            pq.push({capital[i],profits[i]});
        }
        priority_queue<int>pq1;
        while(k--){
            int w1,p1;
            while(!pq.empty()){
                auto it=pq.top();
                int w0=it.first;
                int p0=it.second;
                if(w0>w){
                    break;
                }
                pq.pop();
                pq1.push(p0);
            }
            if(!pq1.empty()){
                w+=pq1.top();
                pq1.pop();
            }
            else break;
        }
        return w;
    }
};