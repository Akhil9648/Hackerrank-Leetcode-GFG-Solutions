class Solution {
public:
    int compute(int n,vector<int>& curr){
        vector<int>srt=curr;
        sort(srt.begin(),srt.end(),greater<int>());
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,srt[i]*(i+1));
        }
        return maxi;
    }
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>curr(m,0);
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]>0) curr[j]+=matrix[i][j];
                else curr[j]=0;
            }
            int ans=compute(m,curr);
            maxi=max(maxi,ans);
        }
        return maxi;
    }
};