class Solution {
public:
    bool isPerfectSquare(int num) {
        int low=0,high=num;
        while(low<=high){
            int mid=(low+high)/2;
            if(1LL*mid*mid>num){
                high=mid-1;
            }
            else if(mid*mid==num) return true;
            else low=mid+1;
        }
        return false;
    }
};