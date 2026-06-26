class DSU {
public:
    vector<int> parent;
    vector<int> rank;
    int components;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);
        components = n;
    }
    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    bool unite(int x, int y) {
        int parent_x = find(x);
        int parent_y = find(y);

        if (parent_x == parent_y)
            return false;

        if (rank[parent_x] > rank[parent_y]) {
            parent[parent_y] = parent_x;
        } else if (rank[parent_y] > rank[parent_x]) {
            parent[parent_x] = parent_y;
        } else {
            parent[parent_x] = parent_y;
            rank[parent_y] += 1;
        }
        components--;
        return true;
    }

    bool isConnected(int i, int j) { return find(i) == find(j); }

    int getComponents() { return components; }
};
class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);

        for(auto &edge:edges){
            int u = edge[0];
            int v = edge[1];

            dsu.unite(u,v);
        }

        return dsu.getComponents();
    }
};
