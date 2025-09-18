class TaskManager {
public:
    unordered_map<int,pair<int,int>>mp;
    priority_queue<tuple<int,int,int>>pq;
    TaskManager(vector<vector<int>>& tasks) {
        for(auto it:tasks){
            mp[it[1]]={it[0],it[2]};
            pq.push({it[2],it[1],it[0]});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        mp[taskId]={userId,priority};
        pq.push({priority,taskId,userId});
    }

    void edit(int taskId, int newPriority) {
        if(!mp.count(taskId)) return ;
        int uid=mp[taskId].first; 
        mp[taskId].second=newPriority;
        pq.push({newPriority,taskId,uid});
    }
    
    void rmv(int taskId) {
        mp.erase(taskId);
    }
    
    int execTop() {
        while(!pq.empty()){
            auto [a,b,c]=pq.top();
            if(mp.count(b) && mp[b].second==a){
                mp.erase(b);
                pq.pop();
                return c;
            }
        pq.pop();
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */