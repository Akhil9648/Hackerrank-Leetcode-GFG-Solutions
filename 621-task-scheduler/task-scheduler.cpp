class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m=tasks.size();
        vector<int>arr(26,0);
        for(char c:tasks){
            arr[c-'A']++;
        }
        int time=0;
        priority_queue<int>pq;
        for(int i:arr){
            if(i>0) pq.push(i);
        }
        while(!pq.empty()){
            vector<int>temp;
            for(int i=1;i<=n+1;i++){
                if(!pq.empty()){
                    int freq=pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }
            for(int f:temp){
                if(f>0) pq.push(f);
            }
            if(pq.empty()) time+=temp.size();
            else time+=n+1;
        }
        return time;
    }
};