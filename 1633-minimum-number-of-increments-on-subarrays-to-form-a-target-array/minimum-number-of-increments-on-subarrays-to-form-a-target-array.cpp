class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n=target.size();
        int opr=target[0];
        for(int i=1;i<n;i++){
            if(target[i]>target[i-1]){
                opr+=(target[i]-target[i-1]);
            }
        }
        return opr;
    }
};