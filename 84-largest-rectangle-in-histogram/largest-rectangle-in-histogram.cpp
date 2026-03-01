class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int n=heights.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                int ele=st.top();
                st.pop();
                int pse=st.empty()?-1:st.top();
                maxi=max(maxi,heights[ele]*(i-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int e=st.top();
            st.pop();
            int w=st.empty()?-1:st.top();
            maxi=max(maxi,heights[e]*(n-w-1));
        }
        return maxi;
    }
};