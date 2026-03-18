class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>PGE(n,0),NGE(n,0);
        int maxi=0,maxind=-1;
        for(int i=0;i<n;i++){
            maxi=max(maxi,height[i]);
            PGE[i]=maxi;
        }
        maxi=0;
        maxind=-1;
        for(int i=n-1;i>=0;i--){
            maxi=max(maxi,height[i]);
            NGE[i]=maxi;
        }
        int sum=0;
        for(int i=0;i<n;i++){
            int a=min(PGE[i],NGE[i]);
            sum+=(a-height[i]);
        }
        return sum;
    }
};