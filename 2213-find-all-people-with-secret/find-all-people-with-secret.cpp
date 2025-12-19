class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings,
                              int firstPerson) {
        // For every person, we store the meeting time and label of the person
        // met.
        unordered_map<int, vector<pair<int, int>>> graph;
        for (auto& meeting : meetings) {
            int x = meeting[0], y = meeting[1], t = meeting[2];
            graph[x].emplace_back(t, y);
            graph[y].emplace_back(t, x);
        }

        // Priority Queue for BFS. It will store (time of knowing the secret,
        // person) We will pop the person with the minimum time of knowing the
        // secret.
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.emplace(0, 0);
        pq.emplace(0, firstPerson);

        // Visited array to mark if a person is visited or not.
        // We will mark a person as visited after it is dequeued
        // from the queue.
        vector<bool> visited(n, false);

        // Do BFS, but pop minimum.
        while (!pq.empty()) {
            auto [time, person] = pq.top();
            pq.pop();
            if (visited[person]) {
                continue;
            }
            visited[person] = true;
            for (auto [t, nextPerson] : graph[person]) {
                if (!visited[nextPerson] && t >= time) {
                    pq.emplace(t, nextPerson);
                }
            }
        }

        // Since we visited only those people who know the secret
        // we need to return indices of all visited people.
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};