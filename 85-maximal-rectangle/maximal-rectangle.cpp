class Solution {
public:
    int findmax(vector<int>& arr){
        stack<int>st;
        int n=arr.size(),count=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                int e=st.top(); st.pop();
                int l=st.empty()?-1:st.top();
                int w=i-l-1;
                count=max(count,arr[e]*w);
            }
            st.push(i);
        }
        while(!st.empty()){
                int e=st.top(); st.pop();
                int l=st.empty()?-1:st.top();
                int w=n-l-1;
                count=max(count,arr[e]*w);
            }
        return count;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
         if (matrix.empty() || matrix.empty()) return 0;
        int n=matrix.size();
        int m=matrix[0].size();
        int count=0;
        vector<int>arr(m,0);
       for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0') arr[j]=0;
                else arr[j]++;
            }
            int a=findmax(arr);
            count=max(a,count);
        }
        return count;
    }
};