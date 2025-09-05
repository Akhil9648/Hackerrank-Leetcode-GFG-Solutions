class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0,ten=0,twe=0;
        for(int i:bills){
            if(i==5){
                five++;
            }
            else if(i==10 && five>0){
                ten++;
                five--;
            }
            else if(i==20 && (five>0 && ten>0)){
                twe++;
                five--;
                ten--;
            }
            else if(i==20 && five>=3){
                twe++;
                five-=3;
            }
            else return false;
        }
        return true;
    }
};