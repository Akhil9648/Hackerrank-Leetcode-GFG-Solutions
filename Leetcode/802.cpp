class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> reverseGraph(n);
        vector<int> outDegree(n, 0);
        queue<int> q;
        vector<int> result;

        for (int i = 0; i < n; i++) {
            for (int neighbor : graph[i]) {
                reverseGraph[neighbor].push_back(i);
            }
            outDegree[i] = graph[i].size();
            if (outDegree[i] == 0) {
                q.push(i); 
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back(node);

            for (int neighbor : reverseGraph[node]) {
                outDegree[neighbor]--;
                if (outDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        sort(result.begin(), result.end());
        return result;
    }
};
