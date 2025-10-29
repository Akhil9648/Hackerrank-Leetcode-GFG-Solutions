class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int h=0,sum=0;
        int n=citations.size();
        for(int i=0;i<n;i++){
            sum=n-i;
            if(citations[i]>=sum){
                h=sum;
                break;
            }
        }
        return h;
    }
};