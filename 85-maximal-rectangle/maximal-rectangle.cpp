class Solution {
public:
int m,n;
    int max_rec_in_hist(vector<int>& arr){
        int maxi=0;
        stack<int>st;
        for(int i=0;i<m;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                int ele=st.top();
                st.pop();
                int nse=i;
                int pse=st.empty()?-1:st.top();
                maxi=max(maxi,arr[ele]*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int nse=m;
            int ele=st.top();
            st.pop();
            int pse=st.empty()?-1:st.top();
            maxi=max(maxi,arr[ele]*(nse-pse-1));
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        int ans=0;
        vector<int>height(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    height[j]+=1;
                }
                else{
                    height[j]=0;
                }
            }
            ans=max(ans,max_rec_in_hist(height));
        }
        return ans;
    }
};