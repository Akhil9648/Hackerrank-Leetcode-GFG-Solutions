class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int a=0;
        for(auto it:operations){
            if(it=="X++" || it=="++X") a+=1;
            else a-=1;
        }
        return a;
    }
};