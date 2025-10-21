class RecentCounter {
public:
    vector<int>arr;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        int count=0;
        arr.push_back(t);
        for(int i:arr){
            if(i>=(t-3000) && i<=t) count++;
        }
        return count;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */