class RecentCounter {
public:
    queue<int>arr;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        arr.push(t);
        while(arr.front()<t-3000) arr.pop();
        return arr.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */