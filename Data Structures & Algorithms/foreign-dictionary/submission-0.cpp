class Solution {
   public:
    string foreignDictionary(vector<string>& words) {
        int n = 26;
        vector<vector<int>> adj(n);
        vector<int> indegree(n, -1);
        unordered_set<int> valid_nodes;

        for (string word : words) {
            for (char ch : word) {
                int u = ch - 'a';
                if (indegree[u] == -1) {
                    indegree[u] = 0;
                    valid_nodes.insert(u);
                }
            }
        }

        // Build adjacency graph
        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];

            if (w1.length() > w2.length() && w1.substr(0, w2.length()) == w2) {
                return "";
            }
            int min_length = min(w1.length(), w2.length());
            for (int j = 0; j < min_length; j++) {
                if (w1[j] != w2[j]) {
                    int u = w1[j] - 'a';
                    int v = w2[j] - 'a';

                    adj[u].push_back(v);
                    indegree[v]++;
                    break;
                }
            }
        }

        // Seeding
        queue<int> q;
        for (int node : valid_nodes) {
            if (indegree[node] == 0) {
                q.push(node);
            }
        }

        string order = "";
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            order += (char)(curr + 'a');

            for (int next_node : adj[curr]) {
                if (--indegree[next_node] == 0) {
                    q.push(next_node);
                }
            }
        }

        if (order.length() != valid_nodes.size()) {
            return "";
        }
        return order;
    }
};
