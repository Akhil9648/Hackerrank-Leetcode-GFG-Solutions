class Solution {
public:
    int candy(vector<int>& ratings) {
        int ans=0;
        int n=ratings.size();
        int prev=1;
        vector<int>left(n),right(n);
        left[0]=1;
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                prev++;
                left[i]=prev;
            }
            else{
                prev=1;
                left[i]=prev;
            }
        }
        right[n-1]=1;
        prev=1;
        for(int j=n-2;j>=0;j--){
            if(ratings[j]>ratings[j+1]){
                prev++;
                right[j]=prev;
            }
            else{
                prev=1;
                right[j]=prev;
            }
        }
        for(int i=0;i<n;i++){
            ans+=max(left[i],right[i]);
        }
        return ans;
    }
};