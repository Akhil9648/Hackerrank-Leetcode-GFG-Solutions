class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int>st;
        int count=0,n=arr.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                int ele=st.top(); st.pop();
                int pse=st.empty()?-1:st.top();
                count=max(count,arr[ele]*(i-pse-1));
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
};