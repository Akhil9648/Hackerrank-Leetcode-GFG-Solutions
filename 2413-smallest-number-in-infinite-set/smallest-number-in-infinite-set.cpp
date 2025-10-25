class SmallestInfiniteSet {
public:
priority_queue<int,vector<int>,greater<int>>pq;
unordered_set<int>st;
    SmallestInfiniteSet() {
        for(int i=1;i<=1000;i++){
            pq.push(i);
            st.insert(i);
        }
    }
    
    int popSmallest() {
        int a=pq.top();
        pq.pop();
        st.erase(a);
        return a;
    }
    
    void addBack(int num) {
        if(st.find(num)!=st.end()) return;
        pq.push(num);
        st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */