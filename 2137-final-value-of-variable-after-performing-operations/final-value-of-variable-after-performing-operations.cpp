class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int a=0;
        for(auto it:operations){
            if(it=="X++" || it=="++X") a++;
            else a--;
        }
        return a;
    }
};