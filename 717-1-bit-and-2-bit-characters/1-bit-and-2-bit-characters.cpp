class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n=bits.size();
        int a=0;
        bool flag=false;
        for(int i=0;i<n-1;i++){
            if(bits[i]==1){
                flag=!flag;
            }
            else if(bits[i]==0 && flag==1){
                flag=false;
            }
        }
        return flag==false;
    }
};