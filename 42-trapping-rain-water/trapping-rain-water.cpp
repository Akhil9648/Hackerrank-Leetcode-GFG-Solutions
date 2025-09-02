class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>lmax(n),rmax(n);
        int maxi=INT_MIN;
        for(int i=0;i<n-1;i++){
            maxi=max(maxi,height[i]);
            lmax[i]=maxi;
        }
        maxi=INT_MIN;
        for(int i=n-1;i>=0;i--){
            maxi=max(maxi,height[i]);
            rmax[i]=maxi;
        }
        int count=0;
        for(int i=0;i<n;i++){
            int a=min(lmax[i],rmax[i])-height[i];
            count+=(a>0)?a:0; 
        }
        return count;
    }
};