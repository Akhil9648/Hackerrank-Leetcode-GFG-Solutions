class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>nse(n,n),pse(n,-1);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            if(!st.empty()) nse[i]=st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]) st.pop();
            if(!st.empty()) pse[i]=st.top();
            st.push(i);
        }
        int ans=0;
        int MOD=1e9+7;
        for(int i=0;i<n;i++){
            long long a = (long long)arr[i] * (nse[i]-i) * (i-pse[i]);
            ans=(ans+a)%MOD;
        }
        return ans;
    }
};