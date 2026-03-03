class Solution {
public:
    int findRec(vector<int>& arr){
        int n=arr.size();
        stack<int>st;
        int maxi=0;
        for(int i=0;i<n;i++){
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
            int nse=arr.size();
            int ele=st.top();
            st.pop();
            int pse=st.empty()?-1:st.top();
            maxi=max(maxi,arr[ele]*(nse-pse-1));
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>sum(m,0);
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]!='0') sum[j]++;
                else sum[j]=0;
            }
            maxi=max(maxi,findRec(sum));
            // sum.clear();
        }
        return maxi;
    }
};