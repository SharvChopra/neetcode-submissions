class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        for (auto& edge : prerequisites) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        vector<unordered_set<int>> isPrereq(numCourses);

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }


        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                isPrereq[v].insert(u);

                isPrereq[v].insert(isPrereq[u].begin(), isPrereq[u].end());

                indegree[v]--;
                if (indegree[v] == 0)
                    q.push(v);
            }
        }

        vector<bool> result;
        for (auto& q : queries) {
            int u = q[0], v = q[1];
            result.push_back(isPrereq[v].count(u) > 0);
        }

        return result;
    }
};