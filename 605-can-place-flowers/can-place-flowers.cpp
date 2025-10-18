class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count=0;
        int  m=flowerbed.size();
            if(n==0) return true;
        for(int i=0;i<m;i++){
            if(flowerbed[i]==0){
            bool l=(i==0) || (flowerbed[i-1]==0);
            bool r=(i==m-1) || (flowerbed[i+1]==0);
            if(l && r){
                flowerbed[i]=1;
                n--;
            }
            }
            if(n==0) return true;
        }
        return false;
    }
};