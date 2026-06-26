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
        } else if (rank[parent_x] < rank[parent_y]) {
            parent[parent_x] = parent_y;
        } else {
            parent[parent_x] = parent_y;
            rank[parent_y] += 1;
        }
        components--;
        return true;
    }
    bool isConnected(int x, int y) { return find(x) == find(y); }
    int getComponents() { return components; }
};


class Solution {
public:
    // bool dfs(int u, int parent, unordered_map<int,vector<int>>&adj,vector<bool>&visited){
    //     visited[u] = true;

    //     for(auto&v:adj[u]){
    //         if(!visited[v]){
    //             if(!dfs(v,u,adj,visited)) return false;
    //         }
    //         else if(v!=parent){
    //             return false;
    //         }
    //     }
    //     return true;
    // }
    bool validTree(int n, vector<vector<int>>& edges) {
        // if(edges.size()!=n-1) return false;
        // unordered_map<int,vector<int>>adj(n);
        // for(auto& e:edges){
        //     int u = e[0];
        //     int v = e[1];

        //     adj[u].push_back(v);
        //     adj[v].push_back(u);
        // }

        // vector<bool>visited(n,0);

        // //Loop checking
        // if(!dfs(0,-1,adj,visited)) return false;

        // //CHECK if there is disconnectivity
        // for(int i=0;i<n;i++){
        //     if(visited[i] == false) return false;
        // }
        // return true;
        DSU dsu(n);
        if(edges.size() != n-1){
            return false;
        }
        for(auto&edge:edges){
            int u = edge[0];
            int v = edge[1];

            if(dsu.unite(u,v) == false) return false;
        }

        if(dsu.getComponents() == 1){
            return true;
        }
        return false;

    }
};
