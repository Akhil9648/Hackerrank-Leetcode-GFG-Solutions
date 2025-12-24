class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(),capacity.end(),greater<int>());
        int m=0;
        for(int i:apple){
            m+=i;
        }
        int cnt=0;
        for(int i:capacity){
            if(m<=i){
                cnt++;
                return cnt;
            }
            m-=i;
            cnt++;
        }
        return -1;
    }
};