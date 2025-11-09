class Solution {
public:
    int countOperations(int num1, int num2) {
        int ans=0;
        while(1){
            if(num1<=0 || num2<=0) break;
            if(num1<num2){
                num2-=num1;
            }
            else{
                num1-=num2;
            }
            ans++;
        }
        return ans;
    }
};