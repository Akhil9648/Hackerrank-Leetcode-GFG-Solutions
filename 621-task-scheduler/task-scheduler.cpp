class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>tsk(26,0);
        for(char c:tasks){
            tsk[c-'A']++;
        }
        int time=0;
        priority_queue<int>pq;
        for(int i=0;i<26;i++){
            if(tsk[i]>0) pq.push(tsk[i]);
        }
        vector<int>remaining;
        while(!pq.empty()){
            int it=pq.top();
            pq.pop();
            time++;
            if(it>1) remaining.push_back(it-1);
            if(remaining.empty() && pq.empty()) break;
            int b=n;
            while(b--){
                if(pq.empty() && remaining.empty()) break;
                // arr.push_back(1);
                time++;
                if(pq.size()>0){
                    int a=pq.top();
                    pq.pop();
                    if(a>1) remaining.push_back(a-1);
                }
            }
            for(int i:remaining){
                pq.push(i);
            }
            remaining.clear();
        }
        return time;
    }
};