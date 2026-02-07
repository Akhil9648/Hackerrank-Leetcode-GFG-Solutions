class Solution {
public:
int n;
    bool canEat(int cap,vector<int>& piles,int h){
        int hours=0;
        for(int i=0;i<n;i++){
            hours+=piles[i]/cap;
            if(piles[i]%cap!=0){
                hours++;
            }
            if(hours>h) return false;
        }
        if(hours<=h) return true;
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        n=piles.size();
        int low=1,high=*max_element(piles.begin(),piles.end());
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canEat(mid,piles,h)){
                high=mid-1;
                ans=mid;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};