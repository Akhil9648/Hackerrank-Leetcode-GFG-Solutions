class Solution {
public:
    int conv(int n){
        int cnt=0;
        while(n){
            if(n%2==1) cnt++;
            n/=2;
        }
        return cnt;
    }
    vector<int> sortByBits(vector<int>& arr) {
        int n=arr.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i:arr){
            pq.push({conv(i),i});
        }
        vector<int>ans(n);
        int k=0;
        while(!pq.empty()){
            auto t=pq.top();
            pq.pop();
            ans[k]=t.second;
            k++;
        }
        return ans;
    }
};