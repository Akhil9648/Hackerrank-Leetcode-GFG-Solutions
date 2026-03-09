class MedianFinder {
public:
    vector<int>arr;
    int n=0;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int i=0;
        for(;i<n;i++){
            if(arr[i]>num) break;
        }
        arr.insert(arr.begin()+i,num);
        n++;
    }
    
    double findMedian() {
        if(n%2==0){
            int a=arr[n/2-1]+arr[n/2];
            return (double) a/2;
        }
        else{
            return (double) arr[n/2];
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */