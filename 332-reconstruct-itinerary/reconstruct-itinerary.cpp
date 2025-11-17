class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n=tickets.size();
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
        for (auto &t : tickets) {
            adj[t[0]].push(t[1]);
        }
        stack<string>st;
        vector<string>ans;
        st.push("JFK");
        while(!st.empty()){
            string a=st.top();
            if(!adj[a].empty()){
                auto it=adj[a].top();
                adj[a].pop();
                    st.push(it);
            }else{
                ans.push_back(a);
                st.pop();
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};